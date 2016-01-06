#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm_ext.hpp>

int main() {
    std::vector<int> vec = {5, 4, 3, 2, 1};

    // Test if an input range is sorted.
    // Optionally accepts a comparison predicate.
    bool is_asc = boost::range::is_sorted(vec);
    bool is_desc = boost::range::is_sorted(vec, std::greater<int>());

    std::cout << "vec(5..1) is sorted in ascending order: "
              << (is_asc ? "true" : "false")
              << std::endl;
    std::cout << "vec(5..1) is sorted in descending order: "
              << (is_desc ? "true" : "false")
              << std::endl;
    return 0;
}
