#include <iostream>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    
    ans += n / 5;
    if(n%5) ans++;
    
    cout << ans;
}