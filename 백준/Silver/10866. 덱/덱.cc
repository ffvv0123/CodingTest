#include <iostream>
using namespace std;

const int MX = 100005;
int dat[2*MX+1];
int head = MX, tail = MX;

void push_front(int x){
    dat[--head] = x;
}

void push_back(int x){
    dat[tail++] = x;
}

void pop_front(){
    head++;
}

void pop_back(){
    tail--;
}

int front(){
    return dat[head];
}

int back(){
    return dat[tail-1];
}

void test(){
    int N;
    cin >> N;

    string cmd; int x;
    while(N--) {
        cin >> cmd;
        if (cmd == "push_front") {
            cin >> x;
            push_front(x);
        }
        else if (cmd == "push_back") {
            cin >> x;
            push_back(x);
        }
        else if (cmd == "pop_front") {
            if (tail == head) cout << -1 << '\n';
            else {
                cout << front() << '\n';
                pop_front();
            }
        }
        else if (cmd == "pop_back") {
            if (tail == head) cout << -1 << '\n';
            else {
                cout << back() << '\n';
                pop_back();
            }
        }
        else if (cmd == "size") {
            cout << tail - head << '\n';
        }
        else if (cmd == "empty") {
           cout << (tail == head) << '\n';
        }
        else if (cmd == "front") {
            if (head == tail) cout << -1 << '\n';
            else cout << front() << '\n';
        }
        else if (cmd == "back") {
            if (head == tail) cout << -1 << '\n';
            else cout << back() << '\n';
        }        
    }
}

int main(){
    test();
}