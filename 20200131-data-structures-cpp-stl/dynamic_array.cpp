#include <iostream>
#include <vector>
#include <deque>
#include <numeric>
#include <algorithm>
#include <functional>

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

int main() {

    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b(a.begin(), a.begin() + 3);
    vector<int> c{1, 2, 3, 4, 5};

    print(a);
    print(b);
    print(c);

    int x = 1.1;
    int y{1};
    cout << "(x, y): (" << x << ", " << y << ")\n";

    deque<int> d(7);
    iota(d.begin(), d.end(), 9);
    for (int i = 0; i < (int) d.size(); i++) {
        cout << d[i] << ' ';
    }
    cout << '\n';

    d.pop_front();
    d.push_front(1);

    d.pop_back();
    d.push_back(100);

    for (int i = 0; i < (int) d.size(); i++) {
        cout << d[i] << ' ';
    }

    cout << '\n';

//    reverse(d.begin(), d.end());
//    print(d);

    sort(d.begin(), d.begin() + 4, greater<int>());
    print(d);

    sort(d.begin() + 2, d.begin() + 4, less<int>());
    print(d);

    return 0;
}
