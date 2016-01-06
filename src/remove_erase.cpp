#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Remove elements, shrinking the container in the process.
    // Encapsulates the common erase-remove idiom.
    // Returns a reference to the input container.
    boost::range::remove_erase(vec, 2);

    std::cout << "input vector after remove_erase(vec, 2): ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
