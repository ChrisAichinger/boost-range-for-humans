#include <functional>
#include <iostream>
#include <boost/range/algorithm.hpp>

int main() {
    std::string s = "abccdb";

    std::string::iterator eq_it = boost::range::adjacent_find(s);
    std::string::iterator gt_it = boost::range::adjacent_find(s, std::greater<char>());

    std::cout << "First duplicate character: '" << *eq_it << "' "
              << "at position " << (eq_it - s.begin()) << std::endl;
    std::cout << "First character greater than next: '" << *gt_it << "' "
              << "at position " << (gt_it - s.begin()) << std::endl;
    return 0;
}
