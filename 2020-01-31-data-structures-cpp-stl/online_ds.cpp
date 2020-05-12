#include <iostream>
#include <set>
#include <iterator>

using namespace std;

template <typename T>
void print(T a) {
    if (!a.empty()) {
        for (const auto &x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    } else {
        cout << "Empty Container\n";
    }
}

// This works like greater<T>
template <typename T>
class functor {
public:

    const bool operator () (const T &x, const T &y) const {
        return x > y;
    }

};

int main() {

    set<int> s;
    for (int i = 10; i > 0; i--) {
        s.insert(i);
    }
    print(s);

    set<int, greater<int>> s_r;
    for (int i = 1; i < 11; i++) {
        s_r.insert(i);
    }
    print(s_r);

    set<int, functor<int>> special;
    for (int i = 1; i < 11; i++) {
        special.insert(i);
    }
    print(special);

    set<int>::iterator it = s.find(4);
    cout << "it: " << *it << '\n';

    it = s.find(100);
    if (it == s.end()) {
        cout << "Not found\n";
    }

    s.insert(100);
    it = s.lower_bound(10);
    cout << "it: " << *it << '\n';

    it = s.lower_bound(11);
    cout << "it: " << *it << '\n';

    it = s.upper_bound(8);
    cout << "it: " << *it << '\n';

    return 0;
}
