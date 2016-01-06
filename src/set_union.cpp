#include <iostream>
#include <locale>
#include <boost/range/algorithm.hpp>

bool iless(char lhs, char rhs) {
    std::locale loc;
    return std::toupper(lhs, loc) < std::toupper(rhs, loc);
}

int main() {
    std::string result, iresult;

    // Copy the sorted union of two sorted input ranges (i.e. elements
    // occuring in either range) to an output iterator. Duplicate elements
    // are copied only once.
    // An optional ordering predicate is supported as well.
    // Returns an iterator pointing to the end of the output range.
    boost::range::set_union(std::string{"DFae"}, std::string{"AFbc"},
                            std::back_inserter(result));
    boost::range::set_union(std::string{"aDeF"}, std::string{"AbcF"},
                            std::back_inserter(iresult),
                            iless);

    std::cout << "Union: " << result << std::endl;
    std::cout << "Union (case-insensitive): " << iresult << std::endl;
    return 0;
}
