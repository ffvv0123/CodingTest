#include <iostream>

using namespace std;

int main()

{

	int cnt = 0;	int N;

	

	cin >> N;

	

	cout << N * N + 2 * N << endl;

	

	for(int i = 1; i <=N; i++) {

		for(int j = 1; j <= i; j++) 

			cout << cnt % 2 + 1 << " " << j << '\n';

		cnt++;

	}

	

	for(int i = 1; i <=N; i++) 

		cout << cnt % 2 + 1 << " " << i << '\n';

	cnt++;

	

	for(int i = 1; i <=N; i++) {

		for(int j = i; j <= N; j++) 

			cout << cnt % 2 + 1 << " " << j << '\n';

		cnt++;

	}	

	

}