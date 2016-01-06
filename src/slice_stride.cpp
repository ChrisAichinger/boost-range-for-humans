#include <iostream>
#include <map>
#include <string>

#include <boost/range/adaptors.hpp>

const std::string str = "abcde";

@ifdef PIPE
  @define SLICE sliced
  @define STRIDE strided
@else
  @define SLICE slice
  @define STRIDE stride
@endif

int main() {
    std::cout << "\"" << str << "\" sliced to (1, 4): "
              << (CALL2(boost::adaptors::SLICE,str,1,4))
              << std::endl;
    std::cout << "\"" << str << "\" | strided(2): "
              << (CALL1(boost::adaptors::STRIDE,str,2))
              << std::endl;

    return 0;
}
