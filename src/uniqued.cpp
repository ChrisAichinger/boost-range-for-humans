#include <iostream>
#include <vector>

#include <boost/range/adaptors.hpp>

const std::string str = "f00f";

@ifdef PIPE
  @define UNIQUE uniqued
@else
  @define UNIQUE unique
@endif

int main() {
    // Equal values are unified if they are adjacent. Equal values that are
    // separated by different elements are left untouched.
    std::cout << "Uniqued version of \"" << str << "\": "
              << (CALL0(boost::adaptors::UNIQUE,str))
              << std::endl;

    return 0;
}
