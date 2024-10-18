#include <iostream>
using namespace std;

int score1, score2;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    score1 = a + b + c + d;
    
    cin >> a >> b >> c >> d;
    score2 = a + b + c + d;
    
    if (score1 > score2) cout << score1;
    else cout << score2;
}