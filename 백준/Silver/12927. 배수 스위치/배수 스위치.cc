#include <iostream>
#include <string>
using namespace std;

string status;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> status;
    int N = status.length();
    int answer = 0;

    for(int i = 0; i < N; i++) {
        if(status[i] == 'Y') {
            for(int j = i; j < N; j += i+1) {
                if (status[j] == 'Y') status[j] = 'N';
                else if (status[j] == 'N') status[j] = 'Y';
            }
            answer++;
        }
    }
    cout << answer;

    return 0;
}