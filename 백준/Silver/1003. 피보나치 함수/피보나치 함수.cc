#include <iostream>
using namespace std;

int cnt_0 = 0;
int cnt_1 = 0;

void fibonacci(int n) {
    int fib_arr[41] = {0};

    fib_arr[0] = 0;
    fib_arr[1] = 1;

    for(int i = 2; i <= n; i++){
        fib_arr[i] = fib_arr[i-1] + fib_arr[i-2];
    }
    cnt_0 = fib_arr[n-1];
    cnt_1 = fib_arr[n];

    if (n == 0){
        cnt_0 = 1;
        cnt_1 = 0;
    }
}

int main(){
    cin.tie(NULL);
	ios::sync_with_stdio(false);
    
    int N;
    cin >> N;

    for(int i=0; i < N; i++){
        int trial;
        cin >> trial;
        fibonacci(trial);
        cout << cnt_0 << " " << cnt_1 << '\n';
        cnt_0 = 0;
        cnt_1 = 0;
    }

}