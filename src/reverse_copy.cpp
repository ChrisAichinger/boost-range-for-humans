#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> output;

    // Copies the reversed input range to an output iterator.
    // Returns an iterator to the end of the output range.
    boost::reverse_copy(vec, std::back_inserter(output));

    std::cout << "input vector after reverse_copy(): ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "output vector after reverse_copy(): ";
    boost::range::copy(output, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
