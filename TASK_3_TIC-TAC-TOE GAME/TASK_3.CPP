#include <iostream>
#include <vector>
using namespace std;

class TicTacToe
{
private:
    vector<vector<char>> board;
    char currentPlayer;

    bool isWin()
    {
        for (int i = 0; i < 3; ++i)
        {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    bool isDraw()
    {
        for (const auto &row : board)
        {
            for (char cell : row)
            {
                if (cell == ' ')
                    return false;
            }
        }
        return true;
    }

    void switchPlayer()
    {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void displayBoard()
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << board[i][j] << (j < 2 ? "|" : "\n");
            }
            if (i < 2)
                cout << "-----\n";
        }
    }

public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

    void playGame()
    {
        do
        {
            displayBoard();
            takeTurn();
            if (isWin())
            {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            if (isDraw())
            {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }
            switchPlayer();
        } while (true);
    }

    void takeTurn()
    {
        int move;
        do
        {
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;
        } while (move < 1 || move > 9 || board[(move - 1) / 3][(move - 1) % 3] != ' ');

        board[(move - 1) / 3][(move - 1) % 3] = currentPlayer;
    }
};

int main()
{
    char choice;
    do
    {
        TicTacToe game;
        game.playGame();

        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
