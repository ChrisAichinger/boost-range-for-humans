#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Reverses the input range and returns a reference to it.
    boost::range::reverse(vec);

    std::cout << "reversed input vector: ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
