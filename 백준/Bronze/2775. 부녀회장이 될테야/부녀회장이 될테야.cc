#include <iostream>
using namespace std;

int dp(int k, int n) {
    int array[15][15] = {-1,};

    for(int i=0; i<n; i++){
        array[0][i] = i+1;
    }

    for(int i=0; i<=k; i++){
        array[i][0] = 1;
    }

    for(int i=1; i<=k; i++){
        for(int j=1; j<n; j++){
            array[i][j] = array[i-1][j] + array[i][j-1];
        }
    }

    return array[k][n-1];
}

void ans() {
    int T;
    cin >> T;

    for(int i=0; i < T; i++){
        int k, n;
        cin >> k >> n;

        cout << dp(k, n) << "\n";
    }
}


int main(){
    ans();

    return 0;
}