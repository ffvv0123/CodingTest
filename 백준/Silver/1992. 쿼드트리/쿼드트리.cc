#include <iostream>
using namespace std;

int video[65][65];

void quadtree(int start, int end, int size) {

    bool isClear = true;
    int checker = video[start][end];

    for(int i = start; i < start + size; i++){
        for(int j = end; j < end + size; j++){
            if(checker != video[i][j]){
                isClear = false;
                break;
            }
        }
    }

    if(isClear){
        cout << checker;
    }

    else{
        cout << "(";
        quadtree(start, end, size/2);
        quadtree(start, end + size/2, size/2);
        quadtree(start + size/2, end, size/2);
        quadtree(start + size/2, end + size/2, size/2);
        cout << ")";
    }
}

void ans(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        for (int j = 0; j < tmp.length(); j++){
            video[i][j] = tmp[j] - '0';
        }
    }
    quadtree(0, 0, N);
}

int main(){
    cin.tie(NULL); 
    ios_base::sync_with_stdio(false);

    ans();

    return 0;
}