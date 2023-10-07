#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void update(vector<int> &tree, int node, int start, int end, int index, int val) {
    if (index < start || index > end) {
        return;
    }
    if (start == end) {
        tree[node] += val;
        return;
    }
    update(tree, node * 2, start, (start + end) / 2, index, val);
    update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int find(vector<int> &tree, int node, int start, int end, int k) {
    if (start == end)
        return start;
    if (k <= tree[2 * node])
        return find(tree, 2 * node, start, (start + end) / 2, k);
    else return find(tree, 2 * node + 1, (start + end) / 2 + 1, end, k - tree[2 * node]);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int N;
    int T, X;
    vector<int> tree(8000008);
	cin >> N;
    
    while (N--) {
        cin >> T >> X;
        if (T == 1) update(tree, 1, 1, 2000002, X, 1);
        else {
            int del = find(tree, 1, 1, 2000002, X);
            cout << del << "\n";
            update(tree, 1, 1, 2000002, del, -1);
        }
    }
    
	return 0;
}
