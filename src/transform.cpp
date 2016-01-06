#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

void display_result(const std::vector<int> vec) {
    boost::range::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

int sum(int lhs, int rhs) {
    return lhs + rhs;
}

int square(int i) {
    return i * i;
}

void transform_one() {
    std::vector<int> input = {0, 1, 2, 3, 4};
    std::vector<int> output;

    // transform() applies a unary predicate function to each element in
    // the input range and writes the result to an output iterator.
    // Returns an iterator to the end of the output.
    boost::range::transform(input, std::back_inserter(output), square);

    display_result(output);
}

void transform_two() {
    std::vector<int> input1 = {0, 1, 2, 3, 4};
    std::vector<int> input2 = {3, 3, 5, 5, 5};
    std::vector<int> output;

    // A version that accepts two ranges and a binary predicate function is
    // also available. The two input ranges are combined using the predicate
    // and the result is written to the output iterator.
    // Returns an iterator to the end of the output.
    boost::range::transform(input1, input2, std::back_inserter(output), sum);

    display_result(output);
}

int main() {
    transform_one();
    transform_two();

    return 0;
}
