#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>


int generator() {
    static int i = 0;
    return 2 * i++;
}

int main() {
    std::vector<int> vec(10, 0);

    // Set each element of vec to the result of generator().
    boost::range::generate(vec, generator);

    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
