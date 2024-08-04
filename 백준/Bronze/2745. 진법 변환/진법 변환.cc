#include <iostream>
using namespace std;

string N;
int B;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> B;

    int tmp = 1, length = N.length(), answer = 0;
    
    for(int i=0; i < length; i++) {
        if(N[length - i - 1] >= 'A' && N[length - i - 1] <= 'Z') {
            answer += tmp * (N[length - i - 1] - 'A' + 10);
        }
        else {
            answer += tmp * (N[length - i - 1] - '0');
        }
        tmp *= B;
    }

    cout << answer;

    return 0;
}