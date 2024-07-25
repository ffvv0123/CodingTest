#include <iostream>
using namespace std;

int fibo(int n) {
    int list[50];
    list[0] = 0;
    list[1] = 1;

    for(int i=2; i < 50; i++)
        list[i] = list[i-2] + list[i-1];
    
    return list[n];
}

int main() {
    int n;
    cin >> n;

    cout << fibo(n);
}