#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y;
    int date = 0;
    cin >> x >> y;

    for(int i=1; i < x; i++) {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) 
            date += 31;
        else if (i == 2)
            date += 28;
        else 
            date += 30;
    }
    date += y;

    if(date % 7 == 0) cout << "SUN";
    else if(date % 7 == 1) cout << "MON";
    else if(date % 7 == 2) cout << "TUE";
    else if(date % 7 == 3) cout << "WED";
    else if(date % 7 == 4) cout << "THU";
    else if(date % 7 == 5) cout << "FRI";
    else if(date % 7 == 6) cout << "SAT";

    return 0;
}