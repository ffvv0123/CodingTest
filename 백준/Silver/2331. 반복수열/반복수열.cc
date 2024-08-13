#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int A, P, cnt = 1;
int check[500000];

int get_number(int num, int P) {
    string number = to_string(num);
    int tmp = 0;

    int len = number.length();
    for(int i=len-1; i >= 0; i--) {
        tmp += pow((number[i] - '0'), P);
    }

    return tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(check, 0, sizeof(check));

    cin >> A >> P;
    while(!check[A]) {
        check[A] = cnt++;
        A = get_number(A, P);
    }
    
    cout << check[A] - 1;

    return 0;
}