#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Rotates the input range and returns a reference to it.
    boost::range::rotate(vec, vec.begin() + 2);

    std::cout << "input vector rotated by 2 elements: ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
