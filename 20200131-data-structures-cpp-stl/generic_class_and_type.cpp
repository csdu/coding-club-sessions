#include <iostream>
#include <utility>

using namespace std;

template <typename A>
class abc {
public:
    A a;

    abc(A x) {
        a = x;
    }

};

template <typename A, typename B>
using pp = pair<A, B>;

int main() {

    pp<int, char> p = make_pair(1, 'A');

    abc<float> a(3.14f);

    cout << "p: {" << p.first << ", " << p.second << "}\n\n";
    cout << "a: " << a.a << '\n';

    return 0;
}
