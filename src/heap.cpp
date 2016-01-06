#include <functional>
#include <iostream>
#include <boost/range/algorithm.hpp>


void display(const std::string &caption, const std::vector<int> vec) {
    std::cout << caption;
    boost::copy(vec, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec = {1, 3, 9, 4, 16, 7};

    // make_heap() turns the input range to a heap. By default, a max-heap
    // is created, but this can be overridden by passing a different ordering
    // predicate.
    // Returns a reference to the input range.
    boost::range::make_heap(vec);
    display("Initial heap: ", vec);

    // pop_heap() rearranges the input range so that [0, end-1) is a new
    // max-heap and rng[end-1] holds the previous max element.
    // Removal of elements from the heap always consists of this
    // pop_heap()/pop_back() cascade.
    // Returns a reference to the input range.
    boost::range::pop_heap(vec);
    vec.pop_back();
    display("Heap after pop_heap(): ", vec);

    // push_heap() takes the element at rng[end-1] and inserts it into a
    // pre-existing heap in [0, end-1). Heap insertion always consists
    // of this push_back/push_heap cascade.
    // Returns a reference to the input range.
    vec.push_back(32);
    boost::range::push_heap(vec);
    display("Heap after push_heap(): ", vec);

    // sort_heap() sorts a pre-existing heap in the input range.
    // This destroys the heap properties.
    boost::range::sort_heap(vec);
    display("Heap after sorting: ", vec);

    return 0;
}
