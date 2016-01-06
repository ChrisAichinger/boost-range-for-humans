#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

void display_result(const std::vector<int> vec) {
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "--------- ---------" << std::endl;
    std::cout << "   < 5      >= 5" << std::endl;
}

int main() {
    std::vector<int> vec = {3, 9, 0, 6, 4, 8, 2, 5, 7, 1};

    // partition() reorders the input range so that all elements for which
    // the predicate function is true come first. All others come second.
    // Returns an iterator to the first element of the second group.
    auto middle = boost::range::partition(vec, [](int v) { return v < 5; });

    std::cout << (middle - vec.begin()) << " elements are < 5" << std::endl << std::endl;
    display_result(vec);

    return 0;
}
