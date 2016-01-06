#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

int main() {
    std::vector<int> vec = {1, 3, 5, 2, 4};

    // vec contains two ordered lists of numbers: one in [0, 3) and one in [3, 5).
    // inplace_merge() merges them so that vec contains a single ordered list.
    boost::range::inplace_merge(vec, vec.begin() + 3);

    std::cout << "After merging: ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;


    std::vector<int> vec2 = {5, 3, 1, 4, 2};

    // There is also an overload that accepts an ordering predicate.
    // We use this merge lists of integers sorted largest-number-first.
    boost::range::inplace_merge(vec2, vec2.begin() + 3, std::greater<int>());

    std::cout << "After merging (descending): ";
    boost::range::copy(vec2, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
