#include <string>
#include <vector>

#include <boost/range.hpp>


int main() {
    std::string str = "abcde";
    std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // Convert ranges into begin/end iterators.
    // Mainly useful when writing range-based wrappers for functions that take
    // begin/end iterators as arguments.
    auto str_begin = boost::begin(str);
    auto str_end = boost::end(str);
    auto vec_rbegin = boost::rbegin(vec);
    auto vec_rend = boost::rend(vec);
    auto str_cbegin = boost::const_begin(str);
    auto str_cend = boost::const_end(str);
    auto vec_crbegin = boost::const_rbegin(vec);
    auto vec_crend = boost::const_rend(vec);

    // Suppress unused variable warnings.
    (void)str_begin; (void)str_end;
    (void)vec_rbegin; (void)vec_rend;
    (void)str_cbegin; (void)str_cend;
    (void)vec_crbegin; (void)vec_crend;

    return 0;
}
