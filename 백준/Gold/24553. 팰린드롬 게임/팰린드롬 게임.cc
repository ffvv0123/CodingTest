#include <iostream>
using namespace std;
#define endl '\n'

int main() {
	int T;
	cin >> T;
	
	for(int i =0; i <T; i++) {
		long long N;
		cin >> N;
		
		if(N % 10 == 0)
		    cout << 1 << endl;
		else
		    cout << 0 << endl;
	}
}