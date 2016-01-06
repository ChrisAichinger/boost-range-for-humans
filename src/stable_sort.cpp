#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

void display_result(const std::vector<int> vec) {
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void stable_sort_without_predicate() {
    std::vector<int> vec = {3, 9, 0, 6, 4, 8, 2, 5, 7, 1};

    // stable_sort(...) rearranges vec so that the elements are in ascending
    // order. Equal elements are retain the relative order they had in the
    // input range.
    // Returns a reference to the input range.
    boost::range::stable_sort(vec);

    display_result(vec);
}

void stable_sort_with_predicate() {
    std::vector<int> vec = {3, 9, 0, 6, 4, 8, 2, 5, 7, 1};

    // And overload that takes a sorting predicate is also available:
    boost::range::stable_sort(vec, std::greater<int>());

    display_result(vec);
}

int main() {
    stable_sort_without_predicate();
    stable_sort_with_predicate();

    return 0;
}
