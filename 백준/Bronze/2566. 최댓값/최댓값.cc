#include <iostream>
using namespace std;

void ans(){
    int numbers[10][10];
    int max_num = -1;
    int max_x = -1;
    int max_y = -1;

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++){
            int tmp;
            cin >> tmp;
            numbers[i][j] = tmp;

            if(numbers[i][j] > max_num){
                max_num = numbers[i][j];
                max_x = i;
                max_y = j;
            }
        }
    }
    cout << max_num << "\n";
    cout << max_x + 1 << " " << max_y + 1;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
	ios::sync_with_stdio(false);

    ans();

    return 0;
}