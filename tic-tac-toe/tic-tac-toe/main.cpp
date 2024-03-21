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
        cout << "�÷��̾� " << (currentPlayer == 0 ? 'O' : 'X') << "�� �����Դϴ�. ��ǥ�� �Է��ϼ��� (�� ��): ";
        cin >> row >> col;

        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '.') 
        {
            cout << "��ȿ���� ���� ��ġ�Դϴ�. �ٽ� �Է��ϼ���." << endl;
            continue;
        }

  
        board[row][col] = (currentPlayer == 0) ? 'O' : 'X';

        if (checkWin(board[row][col])) 
        {
            printBoard(); 
            cout << "�÷��̾� " << (currentPlayer == 0 ? 'O' : 'X') << "�� �¸��߽��ϴ�!" << endl;
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
            cout << "���º��Դϴ�." << endl;
            break;
        }

        currentPlayer = 1 - currentPlayer;
    }

    return 0;
}