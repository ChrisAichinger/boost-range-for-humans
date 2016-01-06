#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>


const std::string haystack = "ABC abc abc";


bool iequals(char lhs, char rhs) {
    std::locale loc;
    return std::toupper(lhs, loc) == std::toupper(rhs, loc);
}


void find_demo() {
    auto it = boost::range::find(haystack, 'a');

    // Return an iterator to the first occurance of a value in a range.
    // If the value is not found, the end iterator is returned.
    // No predicate-overload provided, find_if can be used instead.
    std::cout << "First 'a' at index: " << (it - haystack.begin()) << std::endl;
}

void find_if_demo() {
    // Return an iterator to the first element in a range that satisfies the
    // unary predicate.
    // If the value is not found, the end iterator is returned.
    auto it = boost::range::find_if(haystack, [](char c) { return iequals(c, 'a'); });

    std::cout << "First occurrence of 'a' (case-insensitive): "
              << (it - haystack.begin()) << std::endl;
}

void find_first_of_demo() {
    // Return an iterator to the first occurance any element from the second
    // range within the first.
    // If the value is not found, the end iterator is returned.
    auto it = boost::range::find_first_of(haystack, "cb");
    auto iit = boost::range::find_first_of(haystack, "cb", iequals);

    std::cout << "First occurrence of either 'b' or 'c': "
              << (it - haystack.begin()) << std::endl;
    std::cout << "First occurrence of either 'b' or 'c' (case-insensitive): "
              << (iit - haystack.begin()) << std::endl;
}

int main() {
    find_demo();
    find_if_demo();
    find_first_of_demo();

    // std::find_last_of() is currently not wrapped in Boost Range.

    return 0;
}
