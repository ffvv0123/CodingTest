#include <iostream>
using namespace std;

int N, M, tmp;
int city[202];
int path[1001];

void makeSet(int N) {
    for(int i=1; i <= N; i++) city[i] = i;
}

int find(int node) {
    if (city[node] == node) return node;

    city[node] = find(city[node]);
    return city[node];
} 

void merge(int node1, int node2) {
	int parentNode1 = find(node1);
	int parentNode2 = find(node2);
	
	if (parentNode1 == parentNode2) return;
	
	city[parentNode1] = parentNode2;
	return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    cin >> M;

    makeSet(N);

    for(int i=1; i <= N; i++) {
        for(int j=1; j <= N; j++) {
            cin >> tmp;
            if(tmp == 1) {
                merge(i, j);
            }
        }
    }

    for(int i=0; i < M; i++) cin >> path[i];

    for(int i=1; i < M; i++) {
        if (find(path[i-1]) != find(path[i])) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}