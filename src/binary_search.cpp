#include <iostream>
#include <boost/range/algorithm.hpp>

int main() {
    std::string s = "abcddefghijkklmnoopqrstuvwxyyyz";

    // Binary search to determine if a value is contained in a range.
    // Accepts an optional ordering pradicate.
    // Returns true if the value was found, false otherwise.
    bool has_n = boost::range::binary_search(s, 'n');

    std::cout << (has_n ? "'n' is in s" : "'n' is not in s") << std::endl;
    return 0;
}
