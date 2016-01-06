#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/numeric.hpp>

int main() {
    std::vector<int> vec1 = {1, 2, 2};
    std::vector<int> vec2 = {3, 6, 9};

    // Straight-forward wrapper around std::inner_product().
    // Returns the inner product of the two input ranges.
    int ip = boost::inner_product(vec1, vec2, 0);

    // Optionally, two binary predicates can be specified to be used instead
    // of addition and multiplication steps in the calculation.
    // The example shown here is equivalent to the three-argument call.
    int ip2 = boost::inner_product(vec1, vec2, 0,
                                   std::plus<int>(), std::multiplies<int>());

    std::cout << "Inner product: " << ip << std::endl;
    std::cout << "Inner product (explicit binary operations): " << ip2 << std::endl;
    return 0;
}
