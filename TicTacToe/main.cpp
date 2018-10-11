#include <iostream>

#include "Chessboard.h"

int main()
{
    using namespace TicTacToe;

    Chessboard c;
    c.AddChessPiece(1, 1, ChessPieceType::Cross);
    c.AddChessPiece(2, 2, ChessPieceType::Cross);
    c.AddChessPiece(1, 2, ChessPieceType::Circle);
    std::cout << c << std::endl;

    system("pause");
    return 0;
}