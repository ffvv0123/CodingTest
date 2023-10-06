#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[1000001];
    int N, num;
    cin >> N;
    
    for(int i=0; i<N; i++)
        cin >> arr[i];
    
    sort(arr, arr+N);
    
    for(int i=0; i<N; i++)
        cout << arr[i] << '\n';
}