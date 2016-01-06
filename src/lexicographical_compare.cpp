#include <functional>
#include <iostream>
#include <locale>
#include <boost/range/algorithm.hpp>

bool iless(char lhs, char rhs) {
    std::locale loc;
    return std::toupper(lhs, loc) < std::toupper(rhs, loc);
}

int main() {
    std::string s1 = "abc";
    std::string s2 = "ABD";
    std::string s3 = "ab";
    std::vector<int> vec = {'c', 'c'};

    // Compare two ranges lexicographically, by applying operator<(), or a
    // supplied binary predicate to each pair of elements.
    // Can be used as a less-than operator for ranges.
    bool lt_s1_s2 = boost::range::lexicographical_compare(s1, s2);
    bool lt_s1_s3 = boost::range::lexicographical_compare(s1, s3);
    bool lt_s1_vec = boost::range::lexicographical_compare(s1, vec);
    bool ilt_s1_s2 = boost::range::lexicographical_compare(s1, s2, iless);

    std::cout << "lexicographical_compare(s1, s2): " << (lt_s1_s2 ? "true" : "false") << std::endl;
    std::cout << "lexicographical_compare(s1, s3): " << (lt_s1_s3 ? "true" : "false") << std::endl;
    std::cout << "lexicographical_compare(s1, vec): " << (lt_s1_vec ? "true" : "false") << std::endl;
    std::cout << "lexicographical_compare(s1, s2, iequals): " << (ilt_s1_s2 ? "true" : "false")
              << std::endl;
    return 0;
}
