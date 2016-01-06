#include <iostream>
#include <vector>
#include <boost/range/algorithm.hpp>

int main() {
    std::vector<int> src = {1, 2, 3, 4, 5};

    // Copy the contents of a range to an output iterator.
    // A convenience alias exists in namespace boost: boost::copy().
    boost::range::copy(src, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    // Copy the contents of a range into an empty vector.
    std::vector<int> dest1;
    boost::range::copy(src, std::back_inserter(dest1));

    // copy_backward() copies elements from a range, just like copy() does, but:
    //  - it takes an end iterator as second argument
    //  - it copies the elements back-to-front (the last element is copied first,
    //    the first element is copied last)
    //
    // Due to the first point, it won't work with ostream_iterator or
    // back_insert_iterator, so it's of much more limited use than copy().
    std::vector<int> dest(src.size(), 0);
    boost::range::copy_backward(src, dest.end());
    for (int i : dest) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
