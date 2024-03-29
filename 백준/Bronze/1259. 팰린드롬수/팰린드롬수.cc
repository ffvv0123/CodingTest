#include <iostream>
using namespace std;

bool is_pal(string query){
    int size = query.size();

    for(int i=0; i<= size/2; i++){
        if(query[i] == query[size-1-i])
            continue;
        else return false;
    }
    return true;
}

void ans(){
    while(true){
        string query;
        cin >> query;

        if(query == "0") break;

        bool res = is_pal(query);

        if(res){
            cout << "yes\n";
        } else {
            cout <<"no\n";
        }
    }
}

int main(){
    ans();

    return 0;
}