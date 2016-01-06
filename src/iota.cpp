#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>

int main() {
    std::vector<int> vec(5, 0);

    // Fill an input range with a linear range of values.
    // The value of the first element is given as second parameter.
    // Returns a reference to the input range.
    boost::range::iota(vec, 10);

    boost::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
