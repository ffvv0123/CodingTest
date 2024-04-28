#include <iostream>
#include <stack>
using namespace std;

void ans() {
    int N;
    cin >> N;
    
    stack<int> s;
    int min = 1;

    for(int i=0; i < N; i++){
        int tmp;
        cin >> tmp;

        if(tmp == min){
            min++;
        }
        else{
            s.push(tmp);
        }

        while(!s.empty() && s.top() == min){
            s.pop();
            min++;
        }
    }

    if(s.empty()) cout << "Nice";
    else cout << "Sad";
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
	ios::sync_with_stdio(false);

    ans();

    return 0;
}