#include <iostream>
#include <string>
#include <vector>

#include <boost/range.hpp>
// as_literal() and as_array() need explicit imports.
#include <boost/range/as_literal.hpp>
#include <boost/range/as_array.hpp>

using std::cout;
using std::endl;

const char * const csptr = "BOOST";
const char csarr[] = "boost";


void raw_pointer_demo() {
    // Calling Boost Range functions on cstrings doesn't work very well.
    // The first doesn't compile, the second gives size() == 6, as it counts
    // the terminal \0:
    cout << "size(csptr): doesn't compile" /* << boost::size(csptr) */ << endl; 
    cout << "size(csarr): " << boost::size(csarr) << endl;
}

void as_literal_demo() {
    // boost::as_literal() solves both of these problems by converting the
    // cstrings to a string range. The size is 5, as you'd expect from a string.
    cout << "size(as_literal(csptr)): " << boost::size(boost::as_literal(csptr)) << endl;
    cout << "size(as_literal(csarr)): " << boost::size(boost::as_literal(csarr)) << endl;
}

void as_array_demo() {
    // boost::as_array() serves only a documentary purpose.
    // Calling it indicates that the author realizes that the argument is a
    // character array, but explicitly wants to treat it as an array as
    // opposed to a string.
    // Note that the behavior is exactly the same as in raw_pointer_demo().
    cout << "size(as_array(csptr)): doesn't compile"
      /* << boost::size(boost::as_array(csptr)) */ << endl;
    cout << "size(as_array(csarr)): " << boost::size(boost::as_array(csarr)) << endl;
}

int main() {
    cout << "csptr = (const char *)\"boost\"" << endl;
    cout << "csarr = \"boost\"" << endl;

    raw_pointer_demo();
    as_literal_demo();
    as_array_demo();

    return 0;
}
