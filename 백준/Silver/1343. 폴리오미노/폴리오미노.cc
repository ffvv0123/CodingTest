#include <iostream>
using namespace std;

int main(){
    string board, ans;
    cin >> board;

    int cnt = 0;
    for (int i = 0; i < board.length(); i++){
        if(board[i] == '.'){
            ans += ".";
            cnt = 0;
        }
        if (board[i] == 'X'){
            cnt++;            
        }
        if(cnt == 4){
            ans += "AAAA";
            cnt = 0;
        }
        if(cnt == 2 && board[i+1] != 'X'){
            ans += "BB";
            cnt = 0;
        }
    }
    if(board.length() != ans.length()){
        cout << -1;
        return 0;
    }

    cout << ans;
    return 0;
}