#include <iostream>
using namespace std;

int matrix[101][101];

bool checker(int arr[], int N, int L){
    bool flag = true;
    bool visited[N];
    
    for(int i=0; i < N; i++){
        visited[i] = false;
    }

    for(int i=0; i < N - 1; i++){
        if(arr[i] == arr[i+1]) {
            continue;
        }
        else if(arr[i] + 1 == arr[i+1]){ // 현재 칸이 다음 칸 보다 하나 낮음
            if(i - L + 1 < 0){
                flag = false;
                break;
            }

            for(int j = i-L+1; j < i+1; j++){
                if(arr[j] != arr[i] || visited[j]){
                    flag = false;
                    break;
                }
            }

            for(int j = i-L+1; j < i+1; j++){ // L = 2일 떄, 2 3 3 2 이런거 방지할라고
                visited[j] = true;
            }

        }
        else if(arr[i] - 1 == arr[i+1]){ // 현재 칸이 다음 칸 보다 하나 높음
            if(i + L > N - 1){
                flag = false;
                break;
            }

            for(int j = i+1; j < i+L+1; j++){
                if(arr[j] != arr[i + 1] || visited[j]){
                    flag = false;
                    break;
                }                
            }

            for(int j = i+1; j < i+L+1; j++){ // L = 2일 떄, 3 2 2 3 이런거 방지할라고
                visited[j] = true;
            }            

            i += (L - 1);
        }
        else{
            flag = false;
            break;
        }
    }

    return flag;
}

void ans(){
    int N, L;
    cin >> N >> L;

    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            cin >> matrix[i][j];

    int ans = 0;

    for(int i = 0; i < N; i++){
        int test[101];
        for(int j=0; j < N; j++){
            test[j] = matrix[i][j];
        }
        if(checker(test, N, L)) ans++;
    }

    for(int i = 0; i < N; i++){
        int test[101];
        for(int j=0; j < N; j++){
            test[j] = matrix[j][i];
        }
        if(checker(test, N, L)) ans++;
    }
    cout << ans;
}   

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
	ios::sync_with_stdio(false);

    ans();

    return 0;
}
