#include <iostream>

#include <vector>

using namespace std;

int main() {

    int sum;

    int num1[10002] ={0};

    int num2[10002] = {0};

    string s1, s2;

    vector<int> ans;

    

    

    cin >> s1 >> s2;

    

    if(s1.size() < s2.size()) {

        string tmp;

        tmp = s1;

        s1 = s2;

        s2 = tmp;

    }

    

    int size1 = s1.size();

    int size2 = s2.size();

    

    for(int i=0; i<size1; i++){

        num1[i + 1] = s1[i] - '0';

    }

    

    for(int i=0; i<size2; i++){

        num2[i + 1 +(size1 - size2)] = s2[i] - '0';

    }

    

    for(int i=size1; i>0; i--){

        sum = num1[i] + num2[i];

        if(sum >= 10){

            num1[i - 1]++;

            sum -= 10;

        }

        ans.push_back(sum);

    }

    

    if(num1[0] != 0) cout << 1;

    

    for(int i = ans.size() - 1; i>=0; i--)

        cout << ans[i];

    

    return 0;

}