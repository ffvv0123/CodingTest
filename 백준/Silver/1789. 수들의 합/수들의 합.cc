#include<iostream>
using namespace std;

void ans(){
    long S;
    cin >> S;

    int N = 0;

    while(S >= 0){
        S -= ++N;
    }    

    cout << N-1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
	ios::sync_with_stdio(false);

    ans();

    return 0;
}