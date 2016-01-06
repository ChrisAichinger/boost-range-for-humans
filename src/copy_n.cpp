#include <iostream>
#include <vector>
#include <boost/range/algorithm_ext.hpp>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Copy n elements to an output iterator.
    boost::range::copy_n(vec, 3, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
