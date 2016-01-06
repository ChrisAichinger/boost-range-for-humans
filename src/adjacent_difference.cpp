#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>

int main() {
    std::vector<int> vec = {1, 2, 4, 6, 9};
    std::vector<int> differences;
    std::vector<double> fractions;

    // Wrapper around std::adjacent_difference()
    // y[0] = x[0]
    // y[1] = x[1] - x[0]
    // ...
    //
    // Returns an iterator to the end of the output range.
    boost::adjacent_difference(vec, std::back_inserter(differences));

    // The three-argument version takes a binary predicate to use instead
    // of std::minus.
    boost::adjacent_difference(vec, std::back_inserter(fractions),
                               std::divides<double>());

    std::cout << "Differences between adjacent elements: ";
    boost::copy(differences, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "Fractions between adjacent elements: ";
    boost::copy(fractions, std::ostream_iterator<double>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}
