#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> target = {97, 98, 99};

    // Insert a range into a target container at a specified position.
    // Returns a reference to the target container.
    boost::range::insert(target, target.begin() + 2, vec);

    boost::copy(target, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
