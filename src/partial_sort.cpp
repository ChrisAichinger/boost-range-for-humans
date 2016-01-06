#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

void display_result(const std::vector<int> vec) {
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << " sorted" << std::endl << std::endl;
}

void partial_sort_without_predicate() {
    std::vector<int> vec = {3, 9, 0, 6, 4, 8, 2, 5, 7, 1};

    // partial_sort(..., n) rearranges vec so that [0, n) contains the smallest
    // values in vec in sorted order. [n, end) will hold the rest of the
    // elements in random order.
    boost::range::partial_sort(vec, vec.begin() + 5);

    display_result(vec);
}

void partial_sort_with_predicate() {
    std::vector<int> vec = {3, 9, 0, 6, 4, 8, 2, 5, 7, 1};

    // And overload that takes a sorting predicate is also available:
    boost::range::partial_sort(vec, vec.begin() + 5, std::greater<int>());

    display_result(vec);
}

int main() {
    partial_sort_without_predicate();
    partial_sort_with_predicate();

    return 0;
}
