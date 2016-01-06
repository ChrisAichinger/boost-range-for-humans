#include <iostream>

#include <boost/range/counting_range.hpp>
#include <boost/range/irange.hpp>


void irange_demo() {
    // irange() returns a random-access range of numbers from the half-open
    // interval [begin, end).
    for (int i : boost::irange(5, 10)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // In addition to the two parameter version, there's also a three-parameter
    // overload that takes a step size.
    for (int i : boost::irange(1, 10, 2)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void counting_range_demo() {
    // counting_range() returns a range of numbers from the half-open interval
    // [begin, end). For typical value types (int, unsigned, ...), a
    // RandomAccessRange is returned.
    for (int i : boost::counting_range(5, 10)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    irange_demo();
    counting_range_demo();

    return 0;
}
