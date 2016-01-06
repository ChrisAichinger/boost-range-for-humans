#include <functional>
#include <iostream>
#include <locale>
#include <boost/range/algorithm.hpp>

bool iless(char lhs, char rhs) {
    std::locale loc;
    return std::toupper(lhs, loc) < std::toupper(rhs, loc);
}

void upper_bound_without_predicate() {
    std::string s = "accceg";

    // Return an iterator pointing to the first element that is less or equal
    // to the value argument.
    // Requires a sorted (or at least partitioned) input range.
    std::string::iterator it_b = boost::range::upper_bound(s, 'b');
    std::string::iterator it_c = boost::range::upper_bound(s, 'c');

    std::cout << "Index of upper_bound(s, 'b'): " << (it_b - s.begin()) << std::endl;
    std::cout << "Index of upper_bound(s, 'c'): " << (it_c - s.begin()) << std::endl;
}

void upper_bound_with_predicate() {
    std::string s = "aCcCEg";

    // An overload that takes an ordering predicate is also available.
    std::string::iterator it_b = boost::range::upper_bound(s, 'b', iless);
    std::string::iterator it_c = boost::range::upper_bound(s, 'c', iless);

    std::cout << "Index of upper_bound(s, 'b', iless): " << (it_b - s.begin()) << std::endl;
    std::cout << "Index of upper_bound(s, 'c', iless): " << (it_c - s.begin()) << std::endl;
}

int main() {
    upper_bound_without_predicate();
    upper_bound_with_predicate();

    return 0;
}
