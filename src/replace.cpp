#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // replace() is a wrapper for std::replace().
    // It returns a reference to the input range.
    boost::range::replace(vec, 2, 0);

    std::cout << "input vector after replace(vec, 2, 0): ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
