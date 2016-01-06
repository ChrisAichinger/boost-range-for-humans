#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

int main() {
    std::vector<int> vec = {1, 1, 3, 1, 3, 3};
    std::vector<int> output;

    // unique_copy() wraps std::unique_copy(). Elements in the input
    // range are copied to the output iterator if they are not equal to the
    // next input value. The input range is not modified.
    // Returns an iterator to the end of the output range.
    boost::unique_copy(vec, std::back_inserter(output));

    std::cout << "input vector after unique_copy(): ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "output vector after unique_copy(): ";
    boost::range::copy(output, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
