#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>

int main() {
    std::vector<int> src = {3, 4, 5};
    std::vector<int> target = {95, 96, 97, 98, 99};

    // Copy values from one range to another, overwriting the target values.
    boost::range::overwrite(src, target);

    boost::copy(target, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
