#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>

bool is_3_or_4(int i) {
    return i == 3 || i == 4;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Remove elements, shrinking the container in the process.
    // Encapsulates the common erase-remove idiom.
    // Returns a reference to the input container.
    boost::range::remove_erase_if(vec, is_3_or_4);

    std::cout << "input vector after remove_erase_if(vec, is_3_or_4): ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
