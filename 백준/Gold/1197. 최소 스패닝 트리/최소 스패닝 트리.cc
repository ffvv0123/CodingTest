#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, pair<int, int>> T;

vector<T> graph;
int parent[10002];

int findParent(int x){
    if(parent[x] == x) return x;
    else return parent[x] = findParent(parent[x]);
}

void ans(){
    int V, E;
    cin >> V >> E;

    long weight = 0;

    int A, B, C;
    for(int i = 0; i < E; i++){
        cin >> A >> B >> C;
        graph.push_back({C, {A, B}});
    }

    sort(graph.begin(), graph.end());

    for(int i = 1; i <= V; i++){
        parent[i] = i;
    }

    int cnt = 0;

    for(int i = 0; i < graph.size(); i++){
        T edge = graph[i];
        int cost = edge.first;
        int now_node = edge.second.first;
        int next_node = edge.second.second;

        int rootA = findParent(now_node);
        int rootB = findParent(next_node);

        if(rootA != rootB){
            parent[rootB] = rootA;
            weight += cost;
            cnt++;
            if(cnt == V - 1) break;
        }
    }

    cout << weight;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    ans();
    
    return 0;
}
