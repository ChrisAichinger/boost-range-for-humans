#include <iostream>
#include <list>
#include <vector>

#include <boost/range/any_range.hpp>


// any_range() is a range object that can represent vectors, lists, or other
// range objects. It can be used in interfaces to hide the type of the
// underlying range, which decouples the interface from the implementation.
// The different internal storage container types can be used without affecting
// the public interface.
//
// Note that any_range() does not copy the input range. The range remains valid
// only as long as the underlying containers exist. In other words, you can't
// return an any_range() of a temporary variable!
// Hence the static list/vector in the example below.

typedef boost::any_range<int,
                         boost::bidirectional_traversal_tag,
                         int,
                         std::ptrdiff_t
                        > int_any_range;

int_any_range make_range(bool use_list) {
    static std::vector<int> vec = {1, 2, 3};
    static std::list<int> lst = {1, 2, 3};

    if (use_list) {
        return lst;
    } else {
        return vec;
    }
}

int main() {
    for (const auto & i : make_range(false)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
