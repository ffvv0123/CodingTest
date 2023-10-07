#include <iostream>
#include <stack>
using namespace std;

void ans(){
    int N;
    cin  >> N;

    stack<int> st;

    for(int i=0; i < N; i++){
        int oper;
        cin >> oper;

        if(oper == 1){
            int X;
            cin >> X;

            st.push(X);
        }
        else if(oper == 2){
            if(st.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if(oper == 3){
            cout << st.size() << "\n";
        }
        else if(oper == 4){
            if(st.empty()){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(oper == 5){
            if(st.empty()){
                cout << -1 << "\n";
            }
            else{
                cout << st.top() << "\n";

            }
        }
    }
}


int main(){

    cin.tie(NULL);
	ios::sync_with_stdio(false);
    ans();

    return 0;
}
