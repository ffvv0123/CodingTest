#include <iostream>
using namespace std;
#define MAX_SIZE 64

int arr[MAX_SIZE][MAX_SIZE];

void quadtree(int x, int y, int size){
    if(size == 1){
        cout << arr[x][y];
        return;
    }

    bool white, black;  // white: 0, black: 1
    white = black = true;

    for (int i = x; i < x + size; i++){
        for (int j = y; j < y + size; j++){
            if(arr[i][j] == 0) {
                black = false;
            }
            if(arr[i][j] == 1){
                white = false;
            }
        }
    }
    
    if(white == true){
        cout << 0;
        return;
    }

    if(black == true){
        cout << 1;
        return;
    }

    cout << "(";

    quadtree(x, y, size / 2);
    quadtree(x, y + size / 2, size / 2);
    quadtree(x + size / 2, y, size / 2);
    quadtree(x + size / 2, y + size / 2, size / 2);

    cout << ")";
}

int main(){
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        for (int j = 0; j < tmp.length(); j++){
            arr[i][j] = tmp[j] - '0';
        }
    }

    quadtree(0, 0, N);

    return 0;
}