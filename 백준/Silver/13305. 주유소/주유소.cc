#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    ll dist[N];
    ll cost[N];
    for (int i = 1; i < N; i++){
        cin >> dist[i];
    }
    for (int i = 0; i < N;i++){
        cin >> cost[i];
    }
    
    ll idx = cost[0];
    ll money = idx * dist[1];

    for (int i = 1; i < N-1; i++){
        if(idx < cost[i]){
            money += idx * dist[i + 1];
        }
        else{
            idx = cost[i];
            money += idx * dist[i + 1];
        }
    }

    cout << money;
}