#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // remove() is a wrapper for std::remove(). Elements in the input range
    // are reordered, but the size of the input container is not changed.
    // An iterator to the new end is returned.
    std::vector<int>::iterator end_it = boost::range::remove(vec, 2);

    std::cout << "input vector after remove(vec, 2): ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "Index of the returned iterator: " << (end_it - vec.begin());
    std::cout << std::endl;
    return 0;
}
