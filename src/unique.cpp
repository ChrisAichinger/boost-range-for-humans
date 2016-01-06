#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

int main() {
    std::vector<int> vec = {1, 1, 3, 1, 3, 3};

    // unique() is a wrapper for std::unique(). Elements in the input range
    // are reordered, but the size of the input container is not changed.
    // Returns the range [begin, unique_end) by default, where unique_end
    // points one past the last unique element.
    auto unique_rng = boost::range::unique(vec);

    std::cout << "input vector after unique(vec): ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "Range returned by unique(): ";
    boost::range::copy(unique_rng, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
