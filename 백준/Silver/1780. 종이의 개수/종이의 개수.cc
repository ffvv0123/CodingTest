#include <iostream>
using namespace std;

int N;
int num_m1 = 0, num_0 = 0, num_1 = 0;
int paper[2200][2200];

void get_number(int x, int y, int k) {    
    if (k == 1) {
        if (paper[x][y] == -1) num_m1++;
        else if (paper[x][y] == 0) num_0++;
        else if (paper[x][y] == 1) num_1++;

        return;
    }

    int tmp = paper[x][y]; 
    bool checker = false;

    for(int i=x; i < x+k; i++) {
        for(int j=y; j < y+k; j++) {
            if (paper[i][j] == tmp) continue;
            else checker = true;
        }
    }

    if (checker) {
        for(int m=0; m < 3; m++) {
            for(int n=0; n < 3; n++) {
                get_number(x + k/3 * m, y + k/3 * n, k/3);
            }
        }        
    }
    else {
        if (paper[x][y] == -1) num_m1++;
        else if (paper[x][y] == 0) num_0++;
        else if (paper[x][y] == 1) num_1++;
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            cin >> paper[i][j];

    get_number(0, 0, N);
    cout << num_m1 << '\n' << num_0 << '\n' << num_1;

    return 0;
}