#include <iostream>
#include <locale>
#include <boost/range/algorithm.hpp>

bool iequals(char lhs, char rhs) {
    std::locale loc;
    return std::toupper(lhs, loc) == std::toupper(rhs, loc);
}

int main() {
    const std::string haystack = "bbb AAA aaa";

    // Return an iterator to the first occurance of of repeated elements within
    // a range. The repeated elements are passed as count/value arguments,
    // like they are in the fill constructors of vectors or strings.
    // If the value is not found, the end iterator is returned.
    auto it = boost::range::search_n(haystack, 3, 'a');
    auto iit = boost::range::search_n(haystack, 3, 'a', iequals);

    std::cout << "First occurrence of \"aaa\": "
              << (it - haystack.begin()) << std::endl;
    std::cout << "First occurrence of \"aaa\" (case-insensitive): "
              << (iit - haystack.begin()) << std::endl;

    return 0;
}
