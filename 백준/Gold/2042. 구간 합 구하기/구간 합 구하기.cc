#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
long long a[1000002], tree[4000008];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    }
    else {
        long long mid = (start + end) / 2;

        init(2*node, start, mid);
        init(2*node + 1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
}

long long query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    long long mid = (start + end) / 2;
    long long lsum = query(2*node, start, mid, left, right);
    long long rsum = query(2*node+1, mid+1, end, left, right);

    return lsum + rsum;
}

void update_tree(int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;

    tree[node] = tree[node] + diff;
    if (start != end) {
        long long mid = (start + end) / 2;
        update_tree(2*node, start, mid, index, diff);
        update_tree(2*node+1, mid+1, end, index, diff);
    }
}

void update(int n, int index, long long val) {
    long long diff = val - a[index];
    a[index] = val;
    update_tree(1, 0, n-1, index, diff);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    M += K;
    
    for(int i=0; i < N; i++) {
        cin >> a[i];
    }
    
    init(1, 0, N-1);
    
    while(M--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int index; long long val;
            cin >> index >> val;
            update(N, index-1, val);
        }
        else if (cmd == 2) {
            int left, right;
            cin >> left >> right;
            cout << query(1, 0, N-1, left - 1, right - 1) << '\n';
        }
    }

    return 0;
}