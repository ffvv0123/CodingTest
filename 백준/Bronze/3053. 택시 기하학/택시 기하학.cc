#include <iostream>
#define PI 3.14159265358979
using namespace std;

double R;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R;

    cout << fixed;
	cout.precision(6);

    cout << R * R * PI << '\n';
    cout << 2 * R * R;

    return 0;
}