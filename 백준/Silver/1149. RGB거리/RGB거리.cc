#include <iostream>
#include <algorithm>
using namespace std;

int RGB[1001][3];
int res[1001][3];

void ans(){
    int N;
    cin >> N;

    for(int i=0; i < N; i++)
        for(int j=0; j < 3; j++)
            cin >> RGB[i][j];

    res[0][0] = RGB[0][0];
    res[0][1] = RGB[0][1];
    res[0][2] = RGB[0][2];
    

    for(int i=1; i < N; i++){
        res[i][0] = min(res[i-1][1], res[i-1][2]) + RGB[i][0];
        res[i][1] = min(res[i-1][0], res[i-1][2]) + RGB[i][1];
        res[i][2] = min(res[i-1][0], res[i-1][1]) + RGB[i][2];
    }

    cout << min(min(res[N-1][0], res[N-1][1]), min(res[N-1][1], res[N-1][2]));
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
	ios::sync_with_stdio(false);

    ans();

    return 0;
}