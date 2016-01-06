#include <iostream>
#include <sstream>

#include <boost/range/adaptors.hpp>
#include <boost/range/istream_range.hpp>


int main() {
    std::istringstream ss2("1 2 3 4 5");
    auto input_range2 = boost::istream_range<int>(ss2);
    for (int input : input_range2 | boost::adaptors::uniqued) {
        std::cout << input;
    }
    std::cout << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5};
    for (int input : vec | boost::adaptors::uniqued) {
        std::cout << input;
    }
    std::cout << std::endl;

    return 0;
}
