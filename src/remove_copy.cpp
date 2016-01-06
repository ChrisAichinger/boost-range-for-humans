#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> output;

    // remove_copy() wraps std::remove_copy(). Elements in the input
    // range are copied to the output iterator if they are not equal to the
    // removal value. The input range is not modified.
    // Returns an iterator to the end of the output range.
    boost::remove_copy(vec, std::back_inserter(output), 2);

    std::cout << "input vector after remove_copy(): ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "output vector after remove_copy(): ";
    boost::range::copy(output, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
