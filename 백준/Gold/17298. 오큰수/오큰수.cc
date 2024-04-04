#include <iostream>
#include <stack>
using namespace std;


void ans(){
    int N;
    cin >> N;

    stack<int> s;
    int arr[N];
    int res[N];

    for(int i = 0; i < N; i++){
        res[i] = -1;
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++){
        while(!s.empty() && arr[s.top()] < arr[i]) {
            res[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    for(int i = 0; i < N; i++) {
        cout << res[i] << ' ';
    }
}

int main(){
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);

    ans();

    return 0;
}