#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
	int N;
	cin >> N;
	
	stack<int> st;
	vector<int> arr(N + 1);
	vector<int> ans(N + 1, -1);
	
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	
	for(int i = 1; i <= N; i++){
		while(!st.empty() && arr[st.top()] < arr[i]){
			ans[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}
	
	for(int i = 1; i <= N; i++){
		cout << ans[i] << ' ';
	}	
}