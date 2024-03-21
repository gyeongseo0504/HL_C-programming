#include <iostream>

using namespace std;

char board[3][3];

void gangseo() 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            board[i][j] = '.';
        }
    }
}

void printBoard() 
{
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; i++) 
    {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {

            cout << board[i][j];
            if (j < 2) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "  -----" << endl;
        }
    }
}


bool checkWin(char player) 
{

    for (int i = 0; i < 3; i++) 
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || (board[0][i] == player && board[1][i] == player && board[2][i] == player)) 
        {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || (board[0][2] == player && board[1][1] == player && board[2][0] == player)) 
    {
        return true;
    }
    return false;
}

int main() 
{
    int currentPlayer = 0; 
    gangseo();

    while (true) 
    {
        printBoard(); 
        int row, col;
        cout << "플레이어 " << (currentPlayer == 0 ? 'O' : 'X') << "의 차례입니다. 좌표를 입력하세요 (행 열): ";
        cin >> row >> col;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '.') 
        {
            cout << "유효하지 않은 위치입니다. 다시 입력하세요." << endl;
            continue;
        }

  
        board[row][col] = (currentPlayer == 0) ? 'O' : 'X';

        if (checkWin(board[row][col])) 
        {
            printBoard(); 
            cout << "플레이어 " << (currentPlayer == 0 ? 'O' : 'X') << "가 승리했습니다!" << endl;
            break;
        }


        bool isDraw = true;
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                if (board[i][j] == '.') 
                {
                    isDraw = false;
                    break;
                }
            }
            if (!isDraw) break;
        }
        if (isDraw) 
        {
            printBoard(); 
            cout << "무승부입니다." << endl;
            break;
        }

        currentPlayer = 1 - currentPlayer;
    }

    return 0;
}