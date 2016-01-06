#include <iostream>
#include <iterator>
#include <list>
#include <vector>

#include <boost/range/combine.hpp>


int main() {
    std::string str = "abcde";
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // combine() takes several ranges creates a zipped range, that is a range
    // of tuples where each tuple contains corresponding elements from each
    // input range.
    // The input ranges must have the same size!
    // Up to Boost 1.55, two input ranges were supported, with Boost 1.56 and
    // higher an arbitrary number of input ranges can be used.
    for (const auto & zipped : boost::combine(str, vec)) {
        char c; int i;
        boost::tie(c, i) = zipped;

        std::cout << "(" << c << ", " << i << ")" << std::endl;
    }

    return 0;
}
