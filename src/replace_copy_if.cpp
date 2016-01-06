#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

bool is_3_or_4(int i) {
    return i == 3 || i == 4;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> output;

    // replace_copy_if() wraps std::replace_copy_if().
    // Returns an iterator to the end of the output range.
    boost::replace_copy_if(vec, std::back_inserter(output), is_3_or_4, 0);

    std::cout << "input vector after replace_copy_if(): ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "output vector after replace_copy_if(): ";
    boost::range::copy(output, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
