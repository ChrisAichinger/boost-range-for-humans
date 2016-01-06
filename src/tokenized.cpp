#include <iostream>
#include <string>

#include <boost/range/adaptors.hpp>

const auto WORD_RE = boost::regex("\\w+");
const auto WHITESPACE_RE = boost::regex("\\s+");
const auto SUBMATCH_RE = boost::regex("(\\w\\w)(\\w+)");

const std::string str = "Lorem ipsum dolor sit amet";


// For tokenization, pipe variant is preferable because it offers sane
// default parameters. In contrast, the tokenize() function does not
// have default parameter values, which makes it more painful to use.
//
// The iterator/range value type is boost::sub_match, which is equivalent
// to std::sub_match. The best documentation for those classes I've found
// is this: http://www.cplusplus.com/sub_match
//
// More in-depth information can be found on:
// http://www.cplusplus.com/reference/regex/regex_token_iterator/regex_token_iterator/


void whole_match_demo() {
    // A sub-match index of 0 (the default) indicates "give me each match of
    // the RE as a single sub_match object".
    std::cout << "Whole word matches, showing off sub_match objects:" << std::endl;
    for (const auto & token : str | boost::adaptors::tokenized(WORD_RE)) {
        size_t token_begin_idx = token.first - str.begin();
        size_t token_end_idx = token.second - str.begin();
        std::cout << "  "
                  << "token [" << token.str() << "] "
                  << "begin: " << token_begin_idx << "; "
                  << "end: " << token_end_idx << "; "
                  << "length: " << token.length() << ";"
                  << std::endl;
    }
}

void not_matching_demo() {
    // A sub-match index of -1 indicates "give me tokens that don't match the
    // regular expression".
    std::cout << "Tokens separated by whitespace:" << std::endl << "  ";
    for (const auto & token : str | boost::adaptors::tokenized(WHITESPACE_RE, -1)) {
        std::cout << "[" << token << "] ";
    }
    std::cout << std::endl;
}

void one_sub_match_demo() {
    // Positive sub-match indices select the corresponding match group from the regex.
    std::cout << "First two letters of each word:" << std::endl << "  ";
    for (const auto & token : str | boost::adaptors::tokenized(SUBMATCH_RE, 1)) {
        std::cout << "[" << token << "] ";
    }
    std::cout << std::endl;
}

void multi_sub_match_demo() {
    // Multiple sub-matches are selected by passing a vector of sub-match
    // indices. The resulting range contains one entry for each sub-match
    // for every single match.
    // I'm not aware of a direct way to get the sub-match index within
    // the for loop. A workaround is to use the range adaptor indexed().
    std::vector<int> submaps = {1, 2};
    std::cout << "Full split into sub-matches:" << std::endl << "  ";
    for (const auto & token : str | boost::adaptors::tokenized(SUBMATCH_RE, submaps)) {
        std::cout << "[" << token << "] ";
    }
    std::cout << std::endl;
}

int main() {
    whole_match_demo();
    not_matching_demo();
    one_sub_match_demo();
    multi_sub_match_demo();

    return 0;
}
