#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Erase an arbitrary range from a vector.
    boost::range::erase(vec, boost::make_iterator_range(vec.begin() + 1,
                                                        vec.begin() + 4));

    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
