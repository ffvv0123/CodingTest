/**
 * pre-order 결과를 정렬하면 in-order이 된다.
 * BST의 특성에 맞게 트리를 구성한 후, post-order를 돌리면 될 듯.
 * -> 정렬과 굳이 트리를 구성해야 하는 귀찮음
 * 
 * pre-order의 입력: 시작은 root, root보다 작으면 left, 크면 right
 * -> left, right에서도 재귀로 반복시켜
 * 
 * pre-order: right -> root -> left로 출력
 * post-order right -> left -> root로 출력
 */

#include <iostream>
#include <algorithm>
using namespace std;

int tree[10001];
int idx;

void postorder(int left, int right) {
    if(left >= right) return;

    idx = left + 1;
    while(idx < right) {
        if(tree[left] < tree[idx]) break;
        idx++;
    }

    postorder(left+1, idx);
    postorder(idx, right);
    cout << tree[left] << '\n';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num, idx=0;
    while((cin >> num)) {
        tree[idx++] = num;
    }

    postorder(0, idx);

    return 0;
}