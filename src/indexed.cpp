#include <iostream>
#include <string>
#include <vector>
@ifdef PIPE
  @define INDEX indexed
@else
  @define INDEX index
@endif

// The INDEX() implementation in Boost < 1.56 can't be recommended.
// It's clunky and doesn't work with range-based for loops.
// If you can't upgrade, grab the backported "boost-range-indexed-1.56.hpp" and
// "boost-range-traversal-1.56.hpp from this repo. They have to be included
// before other Boost Range headers.
#include "boost-range-indexed-1.56.hpp"
#include <boost/range/adaptors.hpp>

const std::string str = "beebop";


int main() {
    // INDEX() is analogous to Python's enumerate(). Given a Range,
    // it gives access to the elements as well as their indices.
    // Boost 1.56 or higher is required for this to work properly.
    //
    // The (optional) parameter sets the index of the first element (default: 0)
    std::cout << "Enumeration of a string" << std::endl;
    for (const auto & element : CALL1(boost::adaptors::INDEX,str,0)) {
        std::cout << element.index()
                  << " : "
                  << element.value()
                  << std::endl;
    }

    return 0;
}
