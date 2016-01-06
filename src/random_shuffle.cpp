#include <cstdlib>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

int random_generator(int max) {
    return std::rand() % max;
}

int main() {
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // random_shuffle() shuffles the input range so the elements have random order.
    boost::range::random_shuffle(vec);

    // A custom random number generator can be supplied as well.
    boost::range::random_shuffle(vec, random_generator);

    // Display the result.
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
