#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> sums;
    std::vector<int> products;

    // Straight-forward wrapper around std::partial_sum().
    // Returns an iterator to the end of the output range.
    boost::partial_sum(vec, std::back_inserter(sums));
    boost::partial_sum(vec, std::back_inserter(products), std::multiplies<int>());

    std::cout << "Sums(1..5): ";
    boost::copy(sums, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "Products(1..5): ";
    boost::copy(products, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
