#include <iostream>
#include <cstring>
using namespace std;

string a, b;
int answer = 0;
int a_bucket[26];
int b_bucket[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(a_bucket, 0, 26);
    memset(b_bucket, 0, 26);

    cin >> a;
    cin >> b;

    for(int i=0; i < a.length(); i++)
        a_bucket[a[i] - 'a']++;

    for(int i=0; i < b.length(); i++)
        b_bucket[b[i] - 'a']++;
    
    for(int i=0; i < 26; i++) {
        answer += abs(a_bucket[i] - b_bucket[i]);
        }

    cout << answer;

    return 0;
}