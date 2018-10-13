#include <iostream>

#include "Chessboard.h"

int main()
{
    using namespace std;
    using namespace TicTacToe;

    Chessboard c;
    c.AddChessPiece(1, 1, ChessPieceType::Cross);
    c.AddChessPiece(2, 2, ChessPieceType::Cross);
    c.AddChessPiece(1, 2, ChessPieceType::Circle);
    cout << c << endl;

    system("pause");
    return 0;
}