#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int start_year, start_month, start_date;
    int end_year, end_month, end_date;
    int N;

    int year_vacation = 0, month_vacation = 0;
    int current_work = 0;

    cin >> start_year >> start_month >> start_date;
    cin >> end_year >> end_month >> end_date;

    current_work = (end_year - start_year) * 360 + (end_month - start_month) * 30 + (end_date - start_date);
    
    N = current_work / 360;
    month_vacation = min(36, current_work / 30);

    for(int i=1; i <= N; i++) {
        int tmp = i;
        if (tmp % 2 == 0) tmp--;
        year_vacation += 15 + tmp - tmp / 2 - 1;
    }


    cout << year_vacation << " " << month_vacation << '\n';
    cout << current_work << "days";
    
    return 0;
}