#include <iostream>
#include <cstring>
using namespace std;

int N, M, true_num, party_num, answer;
int true_list[51], party_list[51][51];
int parent[52], rank_size[52];

void make_set(int N) {
    for(int i=1; i <= N; i++) {
        parent[i] = i;
        rank_size[i] = 1;
    }
}

int find(int node) {
    if(parent[node] == node) return node;
    parent[node] = find(parent[node]);
    return parent[node];
}

void merge(int node1, int node2) {
	int parentNode1 = find(node1);
	int parentNode2 = find(node2);

	if (parentNode1 == parentNode2) return;
	
	if (rank_size[parentNode1] > rank_size[parentNode2]) {
		parent[parentNode2] = parentNode1;
		rank_size[parentNode1] += rank_size[parentNode2];
	}
	else {
		parent[parentNode1] = parentNode2;
		rank_size[parentNode2] += rank_size[parentNode1];
	}
	return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    make_set(N);
    memset(party_list, 0, sizeof(party_list));
    
    cin >> true_num;
    for(int i=0; i < true_num; i++) {
        cin >> true_list[i];
    }

    for(int i=1; i < true_num; i++) {
        merge(true_list[i-1], true_list[i]);
    }

    for(int i=0; i < M; i++) {
        cin >> party_num;
        for(int j=0; j < party_num; j++) {
            cin >> party_list[i][j];
        }
        for(int j=1; j < party_num; j++) {
            merge(party_list[i][j-1], party_list[i][j]);
        }
    }

    answer = M;
    for(int i=0; i < M; i++) {
        if(find(true_list[0]) == find(party_list[i][0])) {
            answer--;
        }
    }

    cout << answer;

    return 0;
}