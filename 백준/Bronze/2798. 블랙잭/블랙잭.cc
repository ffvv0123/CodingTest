#include <iostream>
using namespace std;

int main() {
	int N, M;
	
	cin >> N >> M;
	
	int* arr = new int[N];
	if (!arr)
		return 1;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int check = N * (N - 1) * (N - 2) / 6;

	int* sum = new int[check];
	if (!sum)
		return 1;

	int a = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = 1; j < N - 1; j++) {
			for (int k = 2; k < N; k++) {
				if (i < j && i < k && j < k) {
					sum[a] = arr[i] + arr[j] + arr[k];
					a++;
				}
			}
		}
	}

	int max = 0;

	for (int i = 0; i < check; i++) {
		if (sum[i] <= M && sum[i] > max)
			max = sum[i];
	}

	cout << max;

	delete[] arr;
	delete[] sum;
	return 0;
}