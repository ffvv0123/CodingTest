#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;

int V, src, dest, dist;
int max_node, max_length = -1;
vector<pair<int, int>> tree[100002];
bool visited[100002] = {false,};

void dfs(int current, int dist) {
    if(visited[current]) return;

    visited[current] = true;

    if(max_length < dist) {
        max_length = dist;
        max_node = current;
    }

    for(int i=0; i < tree[current].size(); i++) {
        dfs(tree[current][i].first, dist + tree[current][i].second);
    }   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> V;
    for(int i=0; i < V; i++) {
        cin >> src;
        while(true) {
            cin >> dest;
            if(dest != -1) {
                cin >> dist;
                tree[src].push_back({dest, dist});
            }
            else break;
        }
    }

    dfs(1, 0);
    
    max_length = 0;
    memset(visited, false, sizeof(visited));

    dfs(max_node, 0);
    cout << max_length;

    return 0;
}