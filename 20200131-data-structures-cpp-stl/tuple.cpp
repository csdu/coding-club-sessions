#include <iostream>
#include <tuple>

using namespace std;

int main() {

    tuple<int, float, char> a = {1, 2.1f, 'A'};

    cout << "a: " << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << '\n';

    return 0;
}
