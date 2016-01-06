#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> output;

    // Copies a rotated input range to an output iterator.
    // Returns an iterator to the end of the output range.
    boost::rotate_copy(vec, vec.begin() + 2, std::back_inserter(output));

    std::cout << "input vector after rotate_copy(): ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "output vector after rotate_copy(): ";
    boost::range::copy(output, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
