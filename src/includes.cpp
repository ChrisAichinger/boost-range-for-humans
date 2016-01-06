#include <iostream>
#include <locale>
#include <boost/range/algorithm.hpp>

bool iless(char lhs, char rhs) {
    std::locale loc;
    return std::toupper(lhs, loc) < std::toupper(rhs, loc);
}

int main() {
    std::string s = "DEabc";
    std::vector<int> vec = {'a', 'b', 'c'};

    // Return true if all of the elements in the second range are included
    // in the first range. Both ranges have to be sorted.
    // An optional ordering predicate is accepted.
    bool has_ab = boost::range::includes(s, std::string{"ab"});
    bool has_de = boost::range::includes(s, std::string{"de"});
    bool has_vec = boost::range::includes(s, vec);
    bool ihas_de = boost::range::includes(s, std::string{"de"}, iless);

    std::cout << "'a' and 'b' in s: " << (has_ab ? "true" : "false") << std::endl;
    std::cout << "'d' and 'e' in s: " << (has_de ? "true" : "false") << std::endl;
    std::cout << "vec{\"abc\"} in s: "
              << (has_vec ? "true" : "false") << std::endl;
    std::cout << "'d' and 'e' in s (case-insensitive): "
              << (ihas_de ? "true" : "false") << std::endl;
    return 0;
}
