/**
 * 남: 받은 수의 배수의 상태 변환
 * 여: 좌우대칭, 많은 구간 전부 바꾸기
 *
 */

#include <iostream>
using namespace std;

int num_switch, num_student, gender, num;
int status[102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> num_switch;
    for (int i = 1; i <= num_switch; i++) cin >> status[i];

    cin >> num_student;
    while (num_student--) {
        cin >> gender >> num;

        if (gender == 1) {
            for (int i = num; i <= num_switch; i += num) {
                status[i] = 1 - status[i];
            }
        }
        else {
            int s = num, e = num;
            while (status[s] == status[e] && s >= 1 && e <= num_switch) {
                if (s == e) {
                    status[s] = 1 - status[s];
                }
                else {
                    status[s] = 1 - status[s];
                    status[e] = 1 - status[e];
                }
                s--;
                e++;
            }
        }
    }

    for (int i = 1; i <= num_switch; i++) {
        cout << status[i] << ' ';
        if (i % 20 == 0) cout << '\n';
    }

    return 0;
}