#include <iostream>
#include <locale>
#include <boost/range/algorithm.hpp>

bool iequals(char lhs, char rhs) {
    std::locale loc;
    return std::toupper(lhs, loc) == std::toupper(rhs, loc);
}

int main() {
    std::string s1 = "abc";
    std::string s2 = "ABC";
    std::string s3 = "ab";
    std::vector<int> vec = {'a', 'b', 'c'};

    // Return true if the input ranges have the same size and their elements
    // are equal. As a range algorithm, it can accept differing underlying
    // containers (e.g. string and vector).
    // Accepts an optional equality predicate.
    bool eq_s1_s2 = boost::range::equal(s1, s2);
    bool eq_s1_s3 = boost::range::equal(s1, s3);
    bool eq_s1_vec = boost::range::equal(s1, vec);
    bool ieq_s1_s2 = boost::range::equal(s1, s2, iequals);

    std::cout << "equal(s1, s2): " << (eq_s1_s2 ? "true" : "false") << std::endl;
    std::cout << "equal(s1, s3): " << (eq_s1_s3 ? "true" : "false") << std::endl;
    std::cout << "equal(s1, vec): " << (eq_s1_vec ? "true" : "false") << std::endl;
    std::cout << "equal(s1, s2, iequals): " << (ieq_s1_s2 ? "true" : "false")
              << std::endl;
    return 0;
}
