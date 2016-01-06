#include <iostream>
#include <vector>

#include <boost/range/adaptors.hpp>

const std::vector<int> vec = { 0, 1, 2 };
const std::vector<const int*> ptr_vec = { &vec[0], &vec[1], &vec[2] };

@ifdef PIPE
  @define INDIRECT indirected
@else
  @define INDIRECT indirect
@endif

int main() {
    // INDIRECT() is a good solution for iterating over a container of pointers
    // or iterators. It avoids the (*it)->... ideom.
    std::cout << "Easy iteration over a vector of pointers" << std::endl;
    for (int i : CALL0(boost::adaptors::INDIRECT,ptr_vec)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
