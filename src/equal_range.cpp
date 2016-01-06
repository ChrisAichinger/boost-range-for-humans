#include <functional>
#include <iostream>
#include <locale>
#include <boost/range/algorithm.hpp>

bool iless(char lhs, char rhs) {
    std::locale loc;
    return std::toupper(lhs, loc) < std::toupper(rhs, loc);
}

int main() {
    std::string s = "abbCCCcccd";   // Note: 'C' sorts before 'c'!

    // equal_range() wraps std::equal_range() and has the same interface.
    // It expects a sorted input range and returns a range (as std::pair<iter>)
    // of elements equal to its second argument.
    // The optional third parameter is a binary sorting predicate that must
    // implement a less-then comparison (not equality comparison).
    // The iterator-pair can be used as input for many Boost Range algorithms.
    auto c_range = boost::range::equal_range(s, 'c');
    auto cC_range = boost::range::equal_range(s, 'c', iless);

    std::cout << "Range of c's in \"" << s << "\": ";
    boost::copy(c_range, std::ostream_iterator<char>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "Range of c's in \"" << s << "\" (case-insensitive): ";
    boost::copy(cC_range, std::ostream_iterator<char>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
