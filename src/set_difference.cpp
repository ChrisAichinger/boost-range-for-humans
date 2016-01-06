#include <iostream>
#include <locale>
#include <boost/range/algorithm.hpp>

bool iless(char lhs, char rhs) {
    std::locale loc;
    return std::toupper(lhs, loc) < std::toupper(rhs, loc);
}

int main() {
    std::string result, iresult;

    // Copy the sorted difference set of two sorted input ranges (i.e. elements
    // occuring in the first but not in the second range) to an output iterator.
    // An optional ordering predicate is supported as well.
    // Returns an iterator pointing to the end of the output range.
    boost::range::set_difference(std::string{"DFae"}, std::string{"AFbc"},
                                 std::back_inserter(result));
    boost::range::set_difference(std::string{"aDeF"}, std::string{"AbcF"},
                                 std::back_inserter(iresult),
                                 iless);

    std::cout << "Difference: " << result << std::endl;
    std::cout << "Difference (case-insensitive): " << iresult << std::endl;
    return 0;
}
