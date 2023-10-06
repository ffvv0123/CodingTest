#include <iostream>
using namespace std;

int arr[50][50];
int getAnswer(int N, int M) {
    int ans = 1;
    int size = N < M ? N : M;

    while(size > 1){
        for (int i = 0; i < N - size + 1; i++){
            for (int j = 0; j < M - size + 1; j++){
                int chk = arr[i][j];
                if (chk == arr[i + size - 1][j] && chk == arr[i][j + size - 1] && chk == arr[i + size - 1][j + size - 1])
                    return size * size;
            }
        }
        size--;
    }
    return 1;
}

int main(){
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++){
        string line;
        cin >> line;
        for (int j = 0; j < M; j++){
            arr[i][j] = line[j] - '0';
        }
    }

    cout << getAnswer(N, M);

    return 0;
}