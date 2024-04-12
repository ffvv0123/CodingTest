#include <iostream>
#include <stack>
#include <string>
using namespace std;

void ans() {
    while(true) {
        string s;
        getline(cin, s);

        if(s == ".") break;

        stack<char> stk;
        bool balance = true;

        for(int i=0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[') {
                stk.push(s[i]);
            }
            else if(s[i] == ')') {
                if(!stk.empty() && stk.top() == '(') {
                    stk.pop();
                }
                else {
                    balance = false;
                    break;
                }
            }
            else if(s[i] == ']') {
                if(!stk.empty() && stk.top() == '[') {
                    stk.pop();
                }
                else {
                    balance = false;
                    break;
                }
            }
        }
        if (!stk.empty() || !balance) cout << "no\n";
        else cout << "yes\n";
    }
}

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    ans();

    return 0;
}