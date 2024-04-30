#include<iostream>
using namespace std;

void ans(){
    long S;
    cin >> S;

    long N = 0;

    while(S > 0){
        N++;
        S -= N;
    }    

    if (S < 0) N--;

    cout << N;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
	ios::sync_with_stdio(false);

    ans();

    return 0;
}