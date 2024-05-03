#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

void ans(){
    int N;
    cin >> N;

    int ans = 0;
    int arr[100002];
    stack<int> height;

    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    height.push(0);

    for(int i=1; i <= N + 1; i++){
        while(!height.empty() && arr[height.top()] > arr[i]){
            int h = height.top();
            height.pop();
            ans = max(ans, arr[h] * (i-1 - height.top()));
        }
        height.push(i);
    }

    cout << ans;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
	ios::sync_with_stdio(false);

    ans();
    
    return 0;
}