#include <iostream>
#include <algorithm>
using namespace std;

int N, tmp_ans = 0, answer = 0;
int weight[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) {
        cin >> weight[i];
    }

    sort(weight, weight + N, greater<int>());

    for(int i=0; i < N; i++) {
        tmp_ans = weight[i];
        answer = max(answer, tmp_ans * (i + 1));
    }

    cout << answer;
    
    return 0;
}