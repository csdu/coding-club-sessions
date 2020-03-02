#include <iostream>

using namespace std;

template <typename T>
void set_value(T &x, T y) {
    x = y;
}

int main() {

    int a = 5;
    double b = 2.14;

    cout << "a: " << a << '\n';
    set_value<int>(a, 4);
    cout << "a: " << a << '\n';

    cout << "b: " << b << '\n';
    set_value<double>(b, 3.14);
    cout << "b: " << b << '\n';

    // It can also work without an explicit type mention!

    cout << endl;

    cout << "a: " << a << '\n';
    set_value(a, 6);
    cout << "a: " << a << '\n';

    cout << "b: " << b << '\n';
    set_value(b, 6.28);
    cout << "b: " << b << '\n';

    return 0;
}
