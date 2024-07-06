#include <iostream>
using namespace std;

class Set {
public:
    int storage[21];

    void init() {
        for(int i = 1; i <= 20; i++) {
            storage[i] = 0;
        }
    }

    void add(int x) {
        if (check(x) == 0) storage[x] = 1;
    }

    void remove(int x) {
        if (check(x) == 1) storage[x] = 0;
    }

    int check(int x) {
        if (storage[x] == 1) return 1;
        return 0;
    }

    void toggle(int x) {
        if (check(x) == 1) remove(x);
        else add(x);
    }

    void all() {
        for(int i = 1; i <= 20; i++) {
            add(i);
        }
    }

    void empty() {
        for(int i = 1; i <= 20; i++) {
            remove(i);
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    Set set;
    set.init();

    string tmp; int x;
    for(int i = 0; i < M; i++) {
        cin >> tmp;
        if (tmp == "add") {
            cin >> x;
            set.add(x);
        }
        else if (tmp == "remove") {
            cin >> x;
            set.remove(x);
        }
        else if (tmp == "check") {
            cin >> x;
            cout << set.check(x) << '\n';
        }
        else if (tmp == "toggle") {
            cin >> x;
            set.toggle(x);
        }
        else if (tmp == "all") {
            set.all();
        }
        else if (tmp == "empty") {
            set.empty();
        }
    }

    return 0;
}