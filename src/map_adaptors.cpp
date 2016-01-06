#include <iostream>
#include <map>
#include <string>

#include <boost/algorithm/string/join.hpp>
#include <boost/range/adaptors.hpp>

const std::map<int, std::string> numbermap = {
    std::make_pair(1, "one"),
    std::make_pair(2, "two"),
    std::make_pair(3, "three"),
};

@ifdef PIPE
  @define KEYS map_keys
  @define VALUES map_values
@else
  @define KEYS keys
  @define VALUES values
@endif

int main() {
    std::cout << "map keys: ";
    for (const auto & key : CALL0(boost::adaptors::KEYS,numbermap)) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    std::cout << "map values: "
              << boost::algorithm::join(CALL0(boost::adaptors::VALUES,numbermap), " ")
              << std::endl;

    return 0;
}
