#include <iostream>
using namespace std;

int is_prime(int num){
    for (int i = 2; i < num; i++){
        if (num % i == 0) return 0;
        
    }
    return 1;
}

bool is_IMS(int num){
    int n1000 = num / 1000;
    int n100 = num % 1000 / 100;
    int n10 = num % 100 / 10;
    int n1 = num % 10;
    int sum = n1000 + n100 + n10 + n1;

    if (sum % 2 == 1 && num > 5) return true;
    return false;
}

bool is_LHS(int num){
    int cnt_primeFactor = 0;
    int cnt_prime = 0;
    for (int i = 2; i <= num; i++) {
        if (num % i == 0) {
            cnt_primeFactor++;
            cnt_prime += is_prime(i);
        }
    }

    if(num == 4 || num == 2 || (cnt_primeFactor > 1 && cnt_prime % 2 == 0))
        return true;
    else
        return false;
}

int main(){
    int N;
    cin >> N;

    bool ims = is_IMS(N);
    bool lhs = is_LHS(N);

    if (ims && !lhs) cout << 1;
    else if (!ims && lhs) cout << 2;
    else if (!ims && !lhs) cout << 3;
    else cout << 4;

    return 0;
}