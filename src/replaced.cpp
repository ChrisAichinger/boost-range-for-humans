#include <iostream>
#include <vector>

#include <boost/range/adaptors.hpp>

const std::string str = "Boboo";

@ifdef PIPE
  @define REPLACE replaced
  @define REPLACE_IF replaced_if
  @define TRANSFORM transformed
@else
  @define REPLACE replace
  @define REPLACE_IF replace_if
  @define TRANSFORM transform
@endif

bool is_b_ignorecase(char c) {
    return c == 'b' || c == 'B';
}

int main() {
    // REPLACE() is a straight-forward, element-wise replace operation.
    // All elements equal to 'o' are replaced with 'a'.
    // To get dynamic control over the replacement string, use TRANSFORM().
    std::cout << "Replace 'o' in \"" << str << "\": "
              << (CALL2(boost::adaptors::REPLACE,str,'o','a'))
              << std::endl;

    // REPLACE_IF() still has a constant replacement value, but whether a
    // substitution should be performed is determined by a predicate.
    std::cout << "Replace upper and lower case 'b's in \"" << str << "\": "
              << (CALL2(boost::adaptors::REPLACE_IF,str,is_b_ignorecase,'j'))
              << std::endl;

    return 0;
}
