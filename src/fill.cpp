#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Fill the whole vector with zero.
    boost::range::fill(vec, 0);

    // Set the first three elements to 42.
    // The order of arguments is (n, value), consistent with fill constructors.
    // n must be smaller or equal to size(vec).
    boost::range::fill_n(vec, 3, 42);

    return 0;
}
