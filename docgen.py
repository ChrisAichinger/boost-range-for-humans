#!/usr/bin/python3

'''Generate documentation in markdown or HTML format'''

import os
import argparse
import csv
import itertools
import subprocess
import textwrap
import types

import jinja2

import headertree


ENC = 'utf-8'
DEFAULT_INPUT = 'exampletable.txt'
DEFAULT_OUTPUT = 'markdown'
DEFAULT_EXT = 'md'
TEMPLATE_DIR = 'templates'
PROGRAM_STDOUT_DIR = 'output'

CHECK_FILES_EXCEPTIONS = ['src/adjacent_filtered_bug.cpp']
CHECK_FUNCTIONS_EXCEPTIONS = [
        'boost::bidirectional_traversal_tag',  # Outside Boost Range
        'boost::regex',                        # Outside Boost Range
        'boost::tie',                          # Outside Boost Range
        'boost::copy',                         # Alias for boost::range::copy
        'boost::sub_match'                     # Not explicitly documented
        ]

CATEGORY_ORDER = ['General',
                  'Ranges',
                  'Utilities',
                  'Adaptors',
                  'Algorithm::Mutating',
                  'Algorithm::Non-mutating',
                  'Algorithm::Set',
                  'Algorithm::Heap',
                  'Algorithm::Permutation',
                  'Algorithm::New',
                  'Algorithm::Numeric',
                  ]


BOOST_VERSION = '1_60_0'
BOOST_HEADER_URL = 'http://www.boost.org/doc/libs/%s/' % BOOST_VERSION
BOOST_DOC_URL = 'http://www.boost.org/doc/libs/%s/libs/range/doc/html/range/reference/' % BOOST_VERSION


class Function(object):
    def __init__(self, name, category, main_header, headers, doclink, examples):
        self.name = name
        self.category = Category(category)
        self.main_header = main_header
        self.headers = headers
        self.doclink = doclink
        self.examples = [Example(cpp_fname) for cpp_fname in examples]

    @classmethod
    def list_from_csv(cls, csv_filename, htree):
        functions = list()
        with open(csv_filename) as csvfile:
            reader = csv.reader(csvfile, delimiter=';')
            for row in reader:
                name, category, main_header, doclink, examples = row
                name = name.strip()
                category = category.strip()
                main_header = main_header.strip()
                doclink = doclink.strip()
                examples = examples.strip().split()

                headers = htree.lookup_sensible(main_header)

                fun = cls(name, category, main_header, headers, doclink,
                          examples)
                functions.append(fun)

        # Ensure there are no duplicate function names.
        assert len(functions) == len(set(fun.name for fun in functions))
        return functions




class Example(object):
    def __init__(self, cpp_fname):
        self.name = os.path.basename(cpp_fname)
        self.cpp_fname = cpp_fname
        self.output_fname = self._make_output_fname(cpp_fname)

        self.code = open(cpp_fname, encoding=ENC).read()
        self.output = open(self.output_fname, encoding=ENC).read()

    def _make_output_fname(self, cpp_fname):
        basename = os.path.basename(cpp_fname).replace('.cpp', '.out')
        return os.path.join(PROGRAM_STDOUT_DIR, basename)


class Category(object):
    def __init__(self, category):
        self.string = category
        self.levels = category.split('::')

    def common_prefix(self, other):
        common = []
        for self_lvl, other_lvl in zip(self.levels, other.levels):
            if self_lvl != other_lvl:
                break
            common.append(self_lvl)

        return common


def check_all_sources_referenced(functions):
    output = subprocess.check_output(['make', '-s', 'list-sources'],
                                     universal_newlines=True)
    sources = set(output.split())
    sources -= set(CHECK_FILES_EXCEPTIONS)

    for fun in functions:
        sources -= set(ex.cpp_fname for ex in fun.examples)

    if sources:
        raise RuntimeError("Not all source files referenced: %r" % sources)


def check_all_functions_referenced(functions):
    cmd = r"""make -s list-sources | xargs sed -ne 's/.*\(boost::[a-zA-Z0-9_:]*\).*/\1/p'"""
    output = subprocess.check_output(cmd, shell=True, universal_newlines=True)
    found_functions = set(output.split())

    found_functions -= set(fun.name for fun in functions)
    found_functions -= set(CHECK_FUNCTIONS_EXCEPTIONS)

    if found_functions:
        raise RuntimeError("Not all functions referenced: %r" % found_functions)


class Writer(object):
    def __init__(self, output_directory, ext):
        self.output_directory = output_directory
        self.ext = ext

        self.environment = jinja2.Environment(
                loader=jinja2.FileSystemLoader(TEMPLATE_DIR),
                autoescape=self._guess_autoescape,
                extensions=['jinja2.ext.autoescape'])

    @staticmethod
    def _guess_autoescape(template_name):
        if template_name is None or '.' not in template_name:
            return False
        ext = template_name.rsplit('.', 1)[1]
        return ext in ('html', 'htm', 'xml')

    def _group_by_category(self, functions):
        def sort_key(fun):
            return fun.category.string

        groups = dict()
        functions.sort(key=sort_key)
        for cat, funs in itertools.groupby(functions, sort_key):
            groups[cat] = list(funs)

        return groups

    def _index_fname(self):
        return os.path.join(self.output_directory, 'index.' + self.ext)

    def _doc_fname(self, function):
        basename = function.name.replace('::', '-')
        return os.path.join(self.output_directory, basename + '.' + self.ext)

    def write(self, functions):
        self.write_index(functions)
        for fun in functions:
            self.write_function(fun)

    def write_function(self, fun):
        entry_view = types.SimpleNamespace()
        entry_view.fun = fun

        template = self.environment.get_template('entry.' + self.ext)
        stream = template.stream(view=entry_view,
                                 indent=textwrap.indent,
                                 len=len,
                                 BOOST_HEADER_URL=BOOST_HEADER_URL,
                                 BOOST_DOC_URL=BOOST_DOC_URL
                                 )
        stream.dump(self._doc_fname(fun))

    def write_index(self, functions):
        groups = self._group_by_category(functions)
        assert set(groups.keys()) == set(CATEGORY_ORDER)

        index_view = []
        last_cat = Category('')
        for cat in CATEGORY_ORDER:
            catobj = Category(cat)
            common = last_cat.common_prefix(catobj)
            common_len = len(common)
            last_cat = catobj

            category_view = types.SimpleNamespace()
            category_view.level_headers = [None] * 7

            changed = catobj.levels[common_len:]
            for i, lvl_name in enumerate(changed):
                category_view.level_headers[common_len + i] = lvl_name

            category_view.functions = sorted(groups[cat],
                                             key=lambda fun: fun.name)

            index_view.append(category_view)

        template = self.environment.get_template('index.' + self.ext)
        stream = template.stream(view=index_view)
        stream.dump(self._index_fname())


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', action='store', default=DEFAULT_INPUT,
                        help='input examples.txt file')
    parser.add_argument('--ext', choices=['md', 'html'], default=DEFAULT_EXT,
                        help='choose output file type')
    parser.add_argument('--targetdir', action='store', default=DEFAULT_OUTPUT,
                        help='set an output directory')

    args = parser.parse_args()

    htree = headertree.Includes(headertree.PREFIX)
    htree.add(headertree.BOOST_MAIN_HEADER)
    htree.add_recursive(headertree.BOOST_PATH)

    functions = Function.list_from_csv(args.input, htree)

    check_all_sources_referenced(functions)
    check_all_functions_referenced(functions)

    w = Writer(args.targetdir, args.ext)
    w.write(functions)

if __name__ == '__main__':
    main()
