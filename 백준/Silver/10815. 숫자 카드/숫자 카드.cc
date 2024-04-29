#include <iostream>
#include <algorithm>
using namespace std;

int card_num[500001];

void ans(){
    int N, M;
    cin >> N;

    for(int i=0; i < N; i++){
        cin >> card_num[i];
    }

    sort(card_num, card_num + N);

    cin >> M;

    for(int i=0; i < M; i++){
        bool flag = false;
        int tmp;
        cin >> tmp;
        
        if(binary_search(card_num, card_num + N, tmp))
            cout << 1 << " ";
        else cout << 0 << " ";
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
	ios::sync_with_stdio(false);

    ans();

    return 0;
}