#include <iostream>
#include <string>

#include <boost/range/adaptors.hpp>

@ifdef PIPE
  @define REVERSE reversed
@else
  @define REVERSE reverse
@endif

int main() {
    std::string str = "abcdefghijklmnopqrstuvwxyz";

    // Reverse iteration order over a range. Pretty straight-forward.
    std::cout << "Reversed abc: "
              << PARENWRAP(CALL0(boost::adaptors::REVERSE,str))
              << std::endl;

    return 0;
}
