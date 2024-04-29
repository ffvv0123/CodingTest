#include <iostream>
using namespace std;

bool space[101][101];

void ans(){
    int N;
    cin >> N;

    for(int i=0; i < N; i++){
        int x, y;
        cin >> x >> y;

        for(int i = x-1; i < x+9; i++){
            for(int j = y-1; j < y+9; j++){
                space[i][j] = true;
            }
        }
    }

    int cnt = 0;
    for(int i=0; i < 100; i++){
        for(int j=0; j < 100; j++){
            if(space[i][j]) cnt++;
        }
    }    
    cout << cnt;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
	ios::sync_with_stdio(false);

    ans();

    return 0;
}