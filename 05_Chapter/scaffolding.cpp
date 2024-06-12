// This program is related to the drill of the end of chapter 5
#include "../std_lib_facilities.h"

int main()
try {

    cout << "Success!\n";

    keep_window_open();
    return 0;
}
catch(exception& e){
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}