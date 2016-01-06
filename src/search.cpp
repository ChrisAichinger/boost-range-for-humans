#include <iostream>
#include <locale>
#include <boost/range/algorithm.hpp>


const std::string haystack = "ABC abc abc";
const std::string needle = "abc";


bool iequals(char lhs, char rhs) {
    std::locale loc;
    return std::toupper(lhs, loc) == std::toupper(rhs, loc);
}


void search_demo() {
    // Return an iterator to the first occurance of one range inside another.
    // If the value is not found, the end iterator is returned.
    auto it = boost::range::search(haystack, needle);
    auto iit = boost::range::search(haystack, needle, iequals);

    std::cout << "First occurrence of \"abc\": " << (it - haystack.begin()) << std::endl;
    std::cout << "First occurrence of \"abc\" (case-insensitive): "
              << (iit - haystack.begin()) << std::endl;
}

void find_end_demo() {
    // Return an iterator to the last occurance of one range inside another.
    // If the value is not found, the end iterator is returned.
    auto it = boost::range::find_end(haystack, needle);
    auto iit = boost::range::find_end(haystack, needle, iequals);

    std::cout << "Last occurrence of \"abc\": " << (it - haystack.begin()) << std::endl;
    std::cout << "Last occurrence of \"abc\" (case-insensitive): "
              << (iit - haystack.begin()) << std::endl;
}

int main() {
    // Note that search() and find_end() have corresponding functionality.
    // This is not to be confused with find_first_of().
    search_demo();
    find_end_demo();

    return 0;
}
