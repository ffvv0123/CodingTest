#include <iostream>
#include <deque>
using namespace std;

void ans() {
    int N;
    deque<int> dq;

    cin >> N;

    for(int i = N; i >= 1; i--){
        dq.push_back(i);
    }

    while(dq.size() != 1){
        dq.pop_back();

        if(dq.size() != 1){
            int tmp = dq.back();
            dq.pop_back();
            dq.push_front(tmp);
        }
        else break;
    }

    cout << dq.front();
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
	ios::sync_with_stdio(false);

    ans();

    return 0;
}