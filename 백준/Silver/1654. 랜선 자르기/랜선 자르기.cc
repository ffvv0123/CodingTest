#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ans() {
    int N, K;
    cin >> N >> K;

    vector<long> v;
    vector<long>::iterator iter;

    for(int i=0; i < N; i++){
        int element;
        cin >> element;
        v.push_back(element);
    }

    sort(v.begin(), v.end());

    iter = v.begin();

    long high = v.back();
    long low = 1;
    long ans = 0;
    
    while(low <= high){
        long mid = (low + high) / 2;
        long lan = 0;
        for (iter = v.begin(); iter!= v.end(); iter++){
            lan += *iter / mid;
        }

        if (lan >= K){
            ans = mid;
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    cout << ans;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ans();
    return 0;
}