#include <functional>
#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

void merge_without_predicate() {
    std::vector<int> input1 = {1, 3, 5};
    std::vector<int> input2 = {2, 4};
    std::vector<int> merged;

    // merged() takes two sorted input ranges and combines them into a single
    // output range, which is written to the output iterator argument.
    // Currently, there's no way to get a merged range directly.
    boost::range::merge(input1, input2, std::back_inserter(merged));

    std::cout << "Merged: ";
    boost::range::copy(merged, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void merge_with_predicate() {
    std::vector<int> input1 = {5, 3, 1};
    std::vector<int> input2 = {4, 2};
    std::vector<int> merged;

    // There is also an overload which takes a sorting predicate. Here, we
    // use it for merging two input ranges sorted largest-number-first.
    boost::range::merge(input1, input2, std::back_inserter(merged), std::greater<int>());

    std::cout << "Merged (descending): ";
    boost::range::copy(merged, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

int main() {
    merge_without_predicate();
    merge_with_predicate();

    return 0;
}
