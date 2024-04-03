/*
* 문제에서 랜선의 각 최대 길이는 2^31 - 1 = 2147483647 이다.
* 이 수는 int 자료형의 최대값을 나타내기 때문에, 오버플로우 이슈가 발생할 수 있다.
* 따라서, long 자료형을 사용하여 오버플로우의 가능성을 없앤다.
*/


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
