#include <iostream>
#define INF 100000000
using namespace std;


int n, m, a, b, c;
int dist[101][101] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> m;

    for(int i=0; i < n; i++) {
        for(int j=0; j < n; j++) {
            dist[i][j] = INF;
            if(i == j) dist[i][j] = 0;
        }
    }

    for(int i=0; i < m; i++) {
        cin >> a >> b >> c;
        dist[a-1][b-1] = min(dist[a-1][b-1], c);
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=0; i < n; i++) {
        for(int j=0; j < n; j++) {
            if(dist[i][j] >= INF) dist[i][j] = 0;
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}