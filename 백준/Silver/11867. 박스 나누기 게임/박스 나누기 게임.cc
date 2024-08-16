/**
 * 게임이론: 쉬운 유형은 대부분 dp로 처리 가능
 * 
 * box1: 돌이 N개, box2: 돌이 M개 있음
 * -> 두 사람이 턴 돌아가면서 게임
 * 
 * 각 사람은 하나의 박스 선택 -> 돌을 전부 비우고, 다른 박스의 돌을 적절히 두 박스로 분배
 * -> 두 박스에는 적어도 1개 이상의 돌이 필요함
 * -> 이 룰 깨지면 지는거임
 * 
 * 홀수개를 남기면 -> 두 박스는 홀 + 짝 : 다음 사람이 짝 날리면 
 * -> 짝수 있으면 A가 이김. 아니면 B 승
 * 
 */

#include <iostream>
using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    if (N % 2 == 0 || M % 2 == 0) cout << 'A';
    else cout << 'B';

    return 0;
}