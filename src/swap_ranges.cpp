#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm/swap_ranges.hpp>

void display_result(int i, const std::vector<int> vec) {
    std::cout << "vec" << i << ": ";
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec1 = {0, 1, 2, 3, 4};
    std::vector<int> vec2 = {5, 6, 7, 8, 9, 10, 11, 12};

    // Swap all elements from range1 with the corresponding element of range2.
    // size(range2) must be equal or larger than size(range1).
    // Returns a reference to range2.
    boost::range::swap_ranges(vec1, vec2);

    display_result(1, vec1);
    display_result(2, vec2);

    return 0;
}
