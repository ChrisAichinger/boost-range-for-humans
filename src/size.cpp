#include <iostream>
#include <string>
#include <vector>

#include <boost/range.hpp>


int main() {
    std::string str = "abcde";
    std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // boost::empty() and boost::size() do about what you'd expect.
    std::cout << "empty(str): " << boost::empty(str) << std::endl;
    std::cout << "size(vec): " << boost::size(vec) << std::endl;

    // Prefer boost::size() over boost::distance(). The former calls the
    // .size() member function if available and degrades to boost::distance()
    // otherwise. Thus, there's no reason to use boost::distance() directly.
    std::cout << "distance(vec): " << boost::distance(vec) << std::endl;

    return 0;
}
