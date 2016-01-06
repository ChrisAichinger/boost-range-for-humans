#include <iostream>
#include <iterator>
#include <sstream>

#include <boost/range.hpp>


int main() {
    std::string s = "Boost Range";

    // sub_range() creates a range object from a begin and end iterator,
    // just like iterator_range() does. However, sub_range() has the container
    // as template type instead of the iterator, making it easier to use.
    //
    // In C++11, auto + make_iterator_range() should largely eliminate the
    // need for explicitly using this class in client code.
    boost::sub_range<std::string> range(s.begin(), s.begin()+5);
    std::cout << range << std::endl;

    return 0;
}
