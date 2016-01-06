#include <iostream>
#include <set>
#include <vector>

#include <boost/range/adaptors.hpp>

const std::vector<int> vec = { 0, 1, 2, 3, 4 };

@ifdef PIPE
  @define ADJACENT_FILTER adjacent_filtered
@else
  @define ADJACENT_FILTER adjacent_filter
@endif

/** Binary predicate that returns true as long as lhs != constructor_arg */
class lhs_neq {
public:
    explicit lhs_neq(int n) : _n(n) {}

    bool operator()(int lhs, int rhs) {
        bool result = (lhs != _n);
        std::cout << "  called lhs_neq(" << lhs << ", " << rhs << ") -> "
                  << (result ? "true" : "false") << std::endl;
        return result;
    }

private:
    int _n;
};


/** Print the results of the ADJACENT_FILTER calls in a readable way */
void print_result(int n, const std::set<int> &seen_values) {
    std::cout << "Pair where lhs = " << n << " removed. Result = {";
    for (int i : vec) {
        if (seen_values.count(i)) {
            std::cout << i << ", ";
        } else {
            std::cout << "   ";
        }
    }
    std::cout << "}" << std::endl;
}


int main() {
    for (int n : {0, 1, 2, 3, 4}) {
        std::set<int> seen_values;

        // ADJACENT_FILTER() calls the binary predicate for every consecutive
        // pair of values in the input range. If the predicate returns false,
        // the first value of the pair is removed from the result range.
        //
        // The last value in the input range is always included (there is no
        // pair where it's the first of the two values).
        for (int i : CALL1(boost::adaptors::ADJACENT_FILTER,vec,lhs_neq(n))) {
            seen_values.insert(i);
        }
        print_result(n, seen_values);
    }

    return 0;
}
