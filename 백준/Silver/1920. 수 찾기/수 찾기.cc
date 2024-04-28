#include <iostream>
#include <algorithm>
using namespace std;

void ans(){
    long N, M;
    cin >> N;

    vector<int> A(N);
    for (auto& element : A) {
        cin >> element;
    }

    sort(A.begin(), A.end());

    cin >> M;

    for(int i=0; i < M; i++){
        long tmp;
        cin >> tmp;

        long low = 0;
        long high = A.size() - 1;
        bool flag = false;

        while(low <= high) {
            long mid = (low + high) / 2;

            if (A[mid] == tmp) {
                flag = true;
                break;
            } 
            else if (tmp < A[mid]) {
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }

        if(flag) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
	ios::sync_with_stdio(false);

    ans();
    
    return 0;
}