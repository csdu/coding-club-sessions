#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class person_list {
private:
    int *a;
public:

    person_list(int n) {
        a = new int[n];
    }

    ~person_list() {
        delete[] a;
    }

    int get(int i) {
        return a[i];
    }

    int operator [] (int i) {
        return a[i];
    }
};

int main() {

    vector<int> v = {1, 2, 3, 4, 5};

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }
    cout << '\n';

    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';

    for (int i = 10; i < 12; i++) {
        v.push_back(i);
    }

    cout << v.front() << ' ' << v.back() << '\n';

    v.back() = 39;
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';

    return 0;
}
