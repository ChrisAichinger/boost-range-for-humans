#include <iostream>
#include <vector>

#include <boost/range/adaptors.hpp>

const std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

@ifdef PIPE
  @define FILTER filtered
@else
  @define FILTER filter
@endif

bool is_even(int n) {
    return n % 2 == 0;
}

int main() {
    std::cout << "vec filetered by is_even(): ";
    for (int i : CALL1(boost::adaptors::FILTER,vec,is_even)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
