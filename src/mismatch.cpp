#include <iostream>
#include <locale>
#include <boost/range/algorithm.hpp>


bool iequals(char lhs, char rhs) {
    std::locale loc;
    return std::toupper(lhs, loc) == std::toupper(rhs, loc);
}


int main() {
    std::string s1 = "abcdefg";
    std::string s2 = "abCdXfg";

    // Return an iterator to the first element that differs between two ranges.
    // An optional comparison predicate is supported.
    auto it_pair = boost::range::mismatch(s1, s2);
    auto iit_pair = boost::range::mismatch(s1, s2, iequals);

    std::cout << "s1 and s2 diverge at position "
              << (it_pair.first - s1.begin())
              << " with values "
              << *(it_pair.first)
              << " and "
              << *(it_pair.second)
              << std::endl;

    std::cout << "s1 and s2 diverge case-insensitively at position "
              << (iit_pair.first - s1.begin())
              << " with values "
              << *(iit_pair.first)
              << " and "
              << *(iit_pair.second)
              << std::endl;

    return 0;
}
