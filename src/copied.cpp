#include <iostream>
#include <string>
#include <vector>

#include <boost/range/adaptors.hpp>

const std::string str = "abcdef";
const std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

@ifdef PIPE
  @define COPY copied
@else
  @define COPY copy
@endif

int main() {
    // COPY() is great because the returned range object has a conversion
    // operator to any container that supports initialization from a begin/end
    // iterator pair.
    // Unfortunately, it takes two arguments that define a slice from the input
    // range to copy. That's nice if you want to slice, but often you don't.
    std::string newstr = CALL2(boost::adaptors::COPY,str,0,4);
    std::vector<int> newvec = CALL2(boost::adaptors::COPY,vec,3,6);

    std::cout << "Copied str[0:4] to new string: " << newstr << std::endl;
    std::cout << "Copied vec[3:6] to new vector: ";
    for (const int i : newvec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
