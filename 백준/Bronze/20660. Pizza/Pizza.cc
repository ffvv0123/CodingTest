#include <iostream>
#include <vector>
using namespace std;

int n, m, k, tmp, answer = 0;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> hate_list;

    cin >> n;
    for(int i=0; i < n; i++) {
        cin >> tmp;
        hate_list.push_back(tmp);
    }

    cin >> m;
    for(int i=0; i < m; i++) {
        cin >> k;
        vector<int> tmp_set;
        bool checker = true;

        for(int j=0; j < k; j++) {
            cin >> tmp;
            tmp_set.push_back(tmp);
        }
        
        
        for(int a=0; a < n; a++) {
            for(int b=0; b < k; b++) {
                if (hate_list[a] == tmp_set[b]) checker = false;
            }
        }

        if (checker) answer++;
    }

    cout << answer;
    
    return 0;
}