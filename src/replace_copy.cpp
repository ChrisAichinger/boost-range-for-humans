#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> output;

    // replace_copy() wraps std::replace_copy().
    // Returns an iterator to the end of the output range.
    boost::replace_copy(vec, std::back_inserter(output), 2, 0);

    std::cout << "input vector after replace_copy(): ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "output vector after replace_copy(): ";
    boost::range::copy(output, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
