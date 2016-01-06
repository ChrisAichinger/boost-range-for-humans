#include <iostream>
#include <locale>
#include <boost/range/algorithm.hpp>

const std::string s = "iUaCgT";


bool iless(char lhs, char rhs) {
    std::locale loc;
    return std::toupper(lhs, loc) < std::toupper(rhs, loc);
}


void min_demo() {
    // Return an iterator pointing to the minimum element in the input range.
    // Optionally, an ordering predicate can be provided.
    auto min_it = boost::range::min_element(s);
    auto imin_it = boost::range::min_element(s, iless);

    std::cout << "min element: " << *min_it << std::endl;
    std::cout << "min element (case insenitive): " << *imin_it << std::endl;
}

void max_demo() {
    // Return an iterator pointing to the maximum element in the input range.
    // Optionally, an ordering predicate can be provided.
    auto max_it = boost::range::max_element(s);
    auto imax_it = boost::range::max_element(s, iless);

    std::cout << "max element: " << *max_it << std::endl;
    std::cout << "max element (case insenitive): " << *imax_it << std::endl;
}

int main() {
    min_demo();
    max_demo();

    return 0;
}
