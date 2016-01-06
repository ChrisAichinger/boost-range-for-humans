#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>


void for_each_unary() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // for_each() takes a range and calls a unary function on each element.
    // Returns the unary predicate function, for whatever odd reason.
    boost::range::for_each(vec, [](int value) {
            std::cout << value << std::endl;
    });
}

void for_each_binary() {
    std::vector<int> even = {2, 4, 6, 8, 5};
    std::vector<int> odd = {1, 3, 5, 7};

    // for_each() takes a two ranges and a binary predicate. The predicate
    // function is called with corresponding values from the two ranges.
    // Iteration stops at the end of the shorter range.
    // Returns the binary predicate function, for whatever odd reason.
    boost::range::for_each(even, odd, [](int e, int o) {
            std::cout << e << " -- " << o << std::endl;
    });
}


int main() {
    std::cout << "Unary for_each():" << std::endl;
    for_each_unary();

    std::cout << std::endl;
    std::cout << "Binary for_each():" << std::endl;
    for_each_binary();

    return 0;
}
