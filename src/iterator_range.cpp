#include <iostream>
#include <iterator>
#include <sstream>

#include <boost/range.hpp>


void iterator_range_demo() {
    std::stringstream ss("The quick brown fox jumps over the lazy dog.");
    auto begin = std::istream_iterator<std::string>(ss);
    auto end = std::istream_iterator<std::string>();

    // iterator_range() creates a range object from a begin and end iterator.
    // Since ranges are constructed implicitly from containers that have
    // .begin() and .end() methods, it's mostly useful for wrapping custom
    // iterators (e.g. turning a database_row_iterator into a range).
    //
    // Note: Contrived example, use istream_range in production code.
    auto range = boost::iterator_range<decltype(begin)>(begin, end);
    for (const auto & word : range) {
        std::cout << "[" << word << "] ";
    }
    std::cout << std::endl;
}

void make_iterator_range_demo() {
    std::stringstream ss("The quick brown fox jumps over the lazy dog.");
    auto begin = std::istream_iterator<std::string>(ss);
    auto end = std::istream_iterator<std::string>();

    // In practice, it's more convenient to use the make_iterator_range()
    // function that deduces the template type automatically.
    for (const auto & word : boost::make_iterator_range(begin, end)) {
        std::cout << "[" << word << "] ";
    }
    std::cout << std::endl;
}

int main() {
    iterator_range_demo();
    make_iterator_range_demo();

    return 0;
}
