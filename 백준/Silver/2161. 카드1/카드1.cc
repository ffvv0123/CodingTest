#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N;
    cin >> N;

    deque<int> q;

    for(int i=0; i < N; i++)
        q.push_back(i+1);
    
    int cnt = 0;
    while(q.size() != 0) {
        if(cnt % 2 == 0) {
            cout << q.front() << ' ';
            q.pop_front();
        }
        else {
            q.push_back(q.front());
            q.pop_front();
        }
        cnt++;
    }

    return 0;
}
