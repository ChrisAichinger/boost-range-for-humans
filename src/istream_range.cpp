#include <iostream>
#include <sstream>

#include <boost/range/adaptors.hpp>
#include <boost/range/istream_range.hpp>


int main() {
    // istream_range() turns an input iterator into a range object.
    // The template argument type defines the type read from the stream.
    // See std::istream_iterator for more information.
    std::istringstream ss("The quick brown fox jumps over the lazy dog.");
    auto input_range = boost::istream_range<std::string>(ss);
    for (const auto &input : input_range | boost::adaptors::strided(2)) {
        std::cout << "[" << input << "] ";
    }
    std::cout << std::endl;

    std::istringstream ss2("8 2");
    auto input_range2 = boost::istream_range<int>(ss2);
    for (int input : input_range2 | boost::adaptors::replaced(8, 4)) {
        std::cout << input;
    }
    std::cout << std::endl;

    return 0;
}
