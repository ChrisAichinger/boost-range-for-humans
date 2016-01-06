#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

void display_result(const std::vector<int> vec) {
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "--------- ^ -------" << std::endl;
    std::cout << "< vec[5]    > vec[5]" << std::endl << std::endl;
}

void nth_element_without_predicate() {
    std::vector<int> vec = {3, 9, 0, 6, 4, 8, 2, 5, 7, 1};

    // nth_element(..., n) arranges so that vec[n] contains the element that
    // would be at index n in a sorted vector. All positions before n contain
    // smaller values (not necessarily sorted). All positions after n contain
    // larger values (not necessarily sorted).
    boost::range::nth_element(vec, vec.begin() + 5);

    display_result(vec);
}

void nth_element_with_predicate() {
    std::vector<int> vec = {3, 6, 0, 9, 4, 8, 2, 7, 5, 1};

    // A version that accepts an explicit ordering predicate is also available.
    boost::range::nth_element(vec, vec.begin() + 5, std::less<int>());

    display_result(vec);
}

int main() {
    nth_element_without_predicate();
    nth_element_with_predicate();

    return 0;
}
