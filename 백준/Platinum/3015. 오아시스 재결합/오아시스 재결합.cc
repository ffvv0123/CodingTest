#include <iostream>

#include <stack>

using namespace std;

int main(){

	int N;	cin >> N;

	

	stack<pair<int, int>> s;

	

	long long result = 0;

	

	for (int i = 0; i < N; i++){

		int height;

		cin >> height;

		

		while (!s.empty() && s.top().first < height) {

		    result += s.top().second;	

			s.pop();

			}

			

		if (s.empty())

		    s.push({height, 1});

		    

		else {

			if (s.top().first == height) {

				pair<int, int> same = s.top();

				s.pop();				

				result += same.second;

				

				if (!s.empty())

				    result++;

				    

				same.second++;

				s.push(same);

			}

			

			else {

				s.push({height, 1});

				result++;

			}						

		}						

	}

	cout << result;

}