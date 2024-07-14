#include <iostream>
using namespace std;

void reverse_array(int a, int b, int arr[]) {
    int tmp;

    for(int i = 0; i <= (b - a) / 2; i++) {
        tmp = arr[a + i];
        arr[a + i] = arr[b - i];
        arr[b - i] = tmp;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int card[21];
    int a, b;

    for(int i=0; i < 20; i++)
        card[i] = i+1;

    for(int i=0; i < 10; i++) {
        cin >> a >> b;
        reverse_array(a-1, b-1, card);
    }

    for(int i=0; i < 20; i++)
        cout << card[i] << " ";
}