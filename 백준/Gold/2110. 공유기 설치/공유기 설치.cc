#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dist;

int search(int n, int c){
    int l_dist = 0;
    int r_dist = dist[n - 1];

    int result;
    
    while (l_dist <= r_dist){
        int install_router = 1;
        int mid_dist = (l_dist + r_dist) / 2;
        int start = dist[0];

        for (int i = 1; i < n; i++){
            int end = dist[i];

            if(end-start >= mid_dist){
                install_router += 1;
                start = end;
            }
        }

        if(install_router >= c){
            result = mid_dist;
            l_dist = mid_dist + 1;
        }
        else{
            r_dist = mid_dist - 1;
        }
    }
    return result;
}

int main(){
    int N, C;
    cin >> N >> C;

    for (int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        dist.push_back(tmp);
    }

    sort(dist.begin(), dist.end());
    cout << search(N, C);

    return 0;
}