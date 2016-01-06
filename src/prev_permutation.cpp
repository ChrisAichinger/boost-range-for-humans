#include <functional>
#include <iostream>
#include <boost/range/algorithm.hpp>

int main() {
    std::string s = "cba";

    // prev_permutation() generates permutations of a sequence.
    // Permutations are generated in lexicographically descending order (or in
    // descending order based on an optional binary predicate).
    // If a smaller permutation could be generated, true is returned, otherwise
    // the largest permutation is generated and false is returned.
    do {
        std::cout << s << " ";
    } while (boost::range::prev_permutation(s));

    std::cout << std::endl;
    return 0;
}
