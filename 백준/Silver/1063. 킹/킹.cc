#include <iostream>
using namespace std;
#define SIZE 8

int chess[8][8] = {0};
int dx[SIZE] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[SIZE] = {1, -1, 0, 0, 1, -1, 1, -1};

int main(){
    string command, king, rock;
    int trial;
    int cmd = 0;

    cin >> king >> rock >> trial;

    // Point of king
    int x1 = '8' - king[1];
    int y1 = king[0] - 'A';

    // Point of rock
    int x2 = '8' - rock[1];
    int y2 = rock[0] - 'A';

    for (int i = 0; i < trial; i++){
        cin >> command;

        if(!command.compare("R"))
            cmd = 0;
        else if(!command.compare("L"))
            cmd = 1;
        else if (!command.compare("B"))
            cmd = 2;
        else if (!command.compare("T"))
            cmd = 3;
        else if (!command.compare("RT"))
            cmd = 4;
        else if (!command.compare("LT"))
            cmd = 5;
        else if (!command.compare("RB"))
            cmd = 6;
        else if (!command.compare("LB"))
            cmd = 7;
        // enum으로 어떻게 잘 하면 깔끔하게 할 수 있을 듯..?

        int kingMoveX = x1 + dx[cmd];
        int kingMoveY = y1 + dy[cmd];

        // king이 범위를 벗어나는 경우
        if(kingMoveX < 0 || kingMoveX >= SIZE || kingMoveY < 0 || kingMoveY >= SIZE)
            continue;
        
        // king과 rock이 겹치면
        if(kingMoveX == x2 && kingMoveY == y2){
            int rockMoveX = x2 + dx[cmd];
            int rockMoveY = y2 + dy[cmd];
            // rock이 범위를 벗어나는 경우
            if(rockMoveX < 0 || rockMoveX >= SIZE || rockMoveY < 0 || rockMoveY >= SIZE)
                continue;
            x2 = rockMoveX;
            y2 = rockMoveY;
        }
        x1 = kingMoveX;
        y1 = kingMoveY;
    }
    cout << (char)(y1 + 'A') << SIZE - x1 << '\n';
    cout << (char)(y2 + 'A') << SIZE - x2 << '\n';

    return 0;
}