#include <iostream>
#include <vector>
using namespace std;

void ans() {
    int N;
    cin >> N;

    vector<int> arr(N);

    for (auto& element : arr) {
        cin >> element;
    }

    for(int i=0; i < N-1; i++){
        for(int j=i; j < N; j++){
            if(arr[i] > arr[j]){
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
    for (auto& element : arr) {
        cout << element << "\n";
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
	ios::sync_with_stdio(false);

    ans();

    return 0;
}