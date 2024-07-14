#include <iostream>
using namespace std;

void checker(int phone_time[], int N) {
    int Y_charge = 0, M_charge = 0;

    for(int i=0; i < N; i++) {
        Y_charge += phone_time[i] / 30;
        M_charge += phone_time[i] / 60;
        
        if (phone_time[i] % 30 >= 0) Y_charge++;
        if (phone_time[i] % 60 >= 0) M_charge++;
    }
    Y_charge *= 10;
    M_charge *= 15;

    if (Y_charge < M_charge) cout << "Y " << Y_charge << '\n';
    else if (M_charge < Y_charge) cout << "M " << M_charge << '\n';
    else cout << "Y M " << Y_charge << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int phone_time[21];

    cin >> N;

    for(int i=0; i < N; i++) 
        cin >> phone_time[i];
    
    checker(phone_time, N);

    return 0;
}