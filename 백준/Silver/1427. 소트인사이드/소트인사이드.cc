#include <iostream>
#include <algorithm>
using namespace std;

char num[11];
string input_data;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> input_data;
    for(int i=0; i < input_data.length(); i++) {
        num[i] = input_data[i];
    }

    sort(num, num + input_data.length(), greater<char>());

    for(int i=0; i < input_data.length(); i++)
        cout << num[i];
    
    return 0;
}