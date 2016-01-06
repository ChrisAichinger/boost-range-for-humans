#include <iostream>
#include <iterator>
#include <list>
#include <vector>

#include <boost/range/join.hpp>


int main() {
    std::string str = "abcde";
    std::vector<char> vec = {'A', 'B', 'C', 'D', 'E'};

    // join() takes two ranges and concatenates them to a single range.
    for (const auto & c : boost::join(str, vec)) {
        std::cout << c;
    }
    std::cout << std::endl;

    return 0;
}
