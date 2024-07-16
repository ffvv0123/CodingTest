#include <iostream>
#include <cstring>
using namespace std;

char starMap[3200][6400];

void star(int i, int j, int N) {
    if (N == 3) {
        starMap[i][j] = '*';
        starMap[i+1][j-1] = '*'; starMap[i+1][j+1] = '*'; 
        for(int k = 0; k < 5; k++)
            starMap[i+2][j-2+k] = '*';
    }
    else {
        star(i, j, N/2);
        star(i + N/2, j - N/2, N/2);
        star(i + N/2, j + N/2, N/2);
    }
}

int main() {
    int N;
    cin >> N;

    memset(starMap, ' ', sizeof(starMap));

    star(0, N-1, N);

    for(int i=0; i < N; i++) {
        for(int j=0; j < 2 * N - 1; j++) {
            cout << starMap[i][j];
        }
        cout << '\n';
    }

    return 0;
}