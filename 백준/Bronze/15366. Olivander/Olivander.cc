#include <iostream>
#include <algorithm>
using namespace std;

int N;
int X[101], Y[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++) cin >> X[i];
    for(int i=0; i < N; i++) cin >> Y[i];

    sort(X, X+N);
    sort(Y, Y+N);

    for(int i=0; i < N; i++) {
        if(X[i] > Y[i]) {
            cout << "NE";
            return 0;
        }
    }
    cout << "DA";
    

    return 0;
}