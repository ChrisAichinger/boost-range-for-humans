#include <functional>
#include <iostream>
#include <boost/range/algorithm.hpp>

bool is_m_or_n(char c) {
    return c == 'm' || c == 'n';
}

int main() {
    std::string s = "abcddefghijkklmmnoopqrstuvwxyyyz";

    int num_o = boost::range::count(s, 'o');
    int num_mn = boost::range::count_if(s, is_m_or_n);

    std::cout << "Input string: \"" << s << "\"" << std::endl;
    std::cout << "Number of 'o' characters: " << num_o << std::endl;
    std::cout << "Number of 'm' and 'n' characters: " << num_mn << std::endl;
    return 0;
}
