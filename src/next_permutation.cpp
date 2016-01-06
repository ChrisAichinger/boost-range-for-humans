#include <functional>
#include <iostream>
#include <boost/range/algorithm.hpp>

int main() {
    std::string s = "abc";

    // next_permutation() generates permutations of a sequence.
    // Permutations are generated in lexicographical order (or the order
    // enforced by an optional binary predicate).
    // If a larger permutation could be generated, true is returned, otherwise
    // the smallest permutation is generated and false is returned.
    do {
        std::cout << s << " ";
    } while (boost::range::next_permutation(s));

    std::cout << std::endl;
    return 0;
}
