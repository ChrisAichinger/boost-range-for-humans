#include <iostream>
#include <vector>

#include <boost/range/adaptors.hpp>

const std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

@ifdef PIPE
  @define TRANSFORM transformed
@else
  @define TRANSFORM transform
@endif

/** Map integers to the alphabet: 0->a, 1->b, ... */
std::string alphabetize(int i) {
    return std::string(1, 'a' + i);
}

int main() {
    // TRANSFORM() is a nice and general way to change elements in a Boost
    // Range. Even type conversions work fluently, as shown here:
    std::cout << "Transform a vector<int> into letters: "
              << (CALL1(boost::adaptors::TRANSFORM,vec,alphabetize))
              << std::endl;

    return 0;
}
