#include <iostream>
#include <algorithm>
using namespace std;

void ans(){
    int N, M;
    char matrix[51][51];

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < M; j++)
            matrix[i][j] = str[j];
    }

    int ans = 10000;

    for (int i = 0; i <= N - 8; ++i) {
        for (int j = 0; j <= M - 8; ++j) {
            int count1 = 0;
            int count2 = 0;
            
            for (int x = 0; x < 8; ++x) {
                for (int y = 0; y < 8; ++y) {
                    char expectedChar = ((x + y) % 2 == 0) ? 'B' : 'W';
                    if (matrix[i + x][j + y] != expectedChar) {
                        count1++;
                    }
                    expectedChar = ((x + y) % 2 == 0) ? 'W' : 'B';
                    if (matrix[i + x][j + y] != expectedChar) {
                        count2++;
                    }
                }
            }

            ans = min(ans, min(count1, count2));
        }
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
