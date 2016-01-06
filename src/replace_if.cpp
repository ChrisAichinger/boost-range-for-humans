#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

bool is_3_or_4(int i) {
    return i == 3 || i == 4;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // replace_if() is a wrapper for std::replace_if().
    // Returns a reference to the input range.
    boost::range::replace_if(vec, is_3_or_4, 0);

    std::cout << "input vector after replace_if(): ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
