#include <iostream>

#include <vector>

using namespace std;

int main(){

	int check[1001][1001];	vector<int> stack;

    int N;

    

    cin >> N;

    cout << N * N + 1 << '\n';

    

    stack.push_back(0);

    

    while(!stack.empty()){

        int tmp = stack.back();

        stack.pop_back();

        

        cout << tmp + 1 << ' ';

        

        if(!check[tmp][0]){

            stack.push_back(tmp);

            check[tmp][0]=1;

        }

        else{

            for(int i=1; i < N; i++){

                if(!check[tmp][i]){

                    int x = tmp;

                    stack.push_back(x);

                    check[x][i]=1;

                    for(x = (x + (N - i)) % N; x != tmp; x = (x + (N - i)) % N){

                        stack.push_back(x);

                        check[x][i]=1;

                    }

                    break;

                }

            }

        }

    }

}