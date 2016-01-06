#!/usr/bin/python3

import sys
import os
import re

BOOST_MAIN_HEADER = '/usr/include/boost/range.hpp'
BOOST_PATH = '/usr/include/boost/range/'
PREFIX = '/usr/include/'
INCLUDE_RE = re.compile(r'\s*#\s*include\s+<([^>]*)>\s*(//.*)?$')


class Includes(object):
    def __init__(self, prefix):
        self.prefix = prefix
        self.includes = dict()
        self.included_by = dict()

    def add(self, path):
        assert path not in self.includes

        self.includes[path] = set()
        with open(path, 'r') as f:
            for line in f:
                line = line.strip()
                m = INCLUDE_RE.match(line)
                if not m:
                    continue

                includename = os.path.join(self.prefix, m.group(1))
                self.includes[path].add(includename)
                self.included_by.setdefault(includename, set()).add(path)

    def add_recursive(self, path):
        for dirpath, dnames, fnames in os.walk(path):
            for f in fnames:
                if f.endswith(".hpp"):
                    self.add(os.path.join(dirpath, f))

    def _lookup(self, path, result):
        if path in result:
            return

        if os.path.exists(path):
            result.append(path)

        included_by = self.included_by.get(path, set())
        for fname in included_by:
            self._lookup(fname, result)

    def _remove_prefix(self, text, prefix):
        if text.startswith(prefix):
            return text[len(prefix):]
        return text

    def lookup(self, path):
        if not path.startswith(PREFIX):
            path = os.path.join(PREFIX, path)

        result = list()
        self._lookup(path, result)
        return [self._remove_prefix(p, PREFIX) for p in result]

    def lookup_sensible(self, path):
        # Don't return subdirectory headers when looking up parent headers.
        headers = self.lookup(path)
        if not headers:
            return headers

        max_slashes = headers[0].count('/')
        return [h for h in headers if h.count('/') <= max_slashes]


def main():
    includes = Includes(PREFIX)
    includes.add(BOOST_MAIN_HEADER)
    includes.add_recursive(BOOST_PATH)

    print('\n'.join(includes.lookup(sys.argv[1])))


if __name__ == '__main__':
    main()
