#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/numeric.hpp>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Straight-forward wrapper around std::accumulate().
    int sum = boost::accumulate(vec, 0);
    int product = boost::accumulate(vec, 1, std::multiplies<int>());

    std::cout << "Sum(1..5): " << sum << std::endl;
    std::cout << "Product(1..5): " << product << std::endl;
    return 0;
}
