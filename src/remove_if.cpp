#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

bool is_3_or_4(int i) {
    return i == 3 || i == 4;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // remove_if() is a wrapper for std::remove_if(). Elements in the input
    // range are reordered, but the size of the input container is not changed.
    // An iterator to the new end is returned.
    std::vector<int>::iterator end_it = boost::range::remove_if(vec, is_3_or_4);

    std::cout << "input vector after remove_if(): ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "Index of the returned iterator: " << (end_it - vec.begin());
    std::cout << std::endl;
    return 0;
}
