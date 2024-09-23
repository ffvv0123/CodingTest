#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
long long a[1000002], tree[4000008];

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start] % 1000000007;
    }
    else {
        long long mid = (start + end) / 2;

        init(2 * node, start, mid);
        init(2 * node + 1, mid + 1, end);
        tree[node] = (tree[2 * node] * tree[2 * node + 1]) % 1000000007;
    }
}

long long query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 1;
    if (left <= start && end <= right) return tree[node];

    long long mid = (start + end) / 2;
    long long lprod = query(2 * node, start, mid, left, right);
    long long rprod = query(2 * node + 1, mid + 1, end, left, right);

    return (lprod * rprod) % 1000000007;
}

void update_tree(int node, int start, int end, int index, long long val) {
    if (index < start || index > end) return;

    if (start == end) tree[node] = val % 1000000007;
    else {
        long long mid = (start + end) / 2;
        update_tree(2 * node, start, mid, index, val);
        update_tree(2 * node + 1, mid + 1, end, index, val);
        tree[node] = (tree[2 * node] * tree[2 * node + 1]) % 1000000007;
    }
}

void update(int n, int index, long long val) {
    a[index] = val;
    update_tree(1, 0, n - 1, index, val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    M += K;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    init(1, 0, N - 1);

    while (M--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int index; long long val;
            cin >> index >> val;
            update(N, index - 1, val);
        }
        else if (cmd == 2) {
            int left, right;
            cin >> left >> right;
            cout << query(1, 0, N - 1, left - 1, right - 1) << '\n';
        }
    }

    return 0;
}