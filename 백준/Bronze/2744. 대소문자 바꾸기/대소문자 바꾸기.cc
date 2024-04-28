#include <iostream>
using namespace std;

void ans(){
    string s;
    cin >> s;

    // A-Z : 65-90
    // a-z : 97-122

    for(int i=0; i < s.length(); i++){
        if(int(s[i]) >= 'A' && int(s[i] <= 'Z'))
            cout << char(int(s[i]) + 32);
        else if(int(s[i]) >= 'a' && int(s[i] <= 'z'))
            cout << char(int(s[i]) - 32);
    }

}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
	ios::sync_with_stdio(false);

    ans();

    return 0;
}
