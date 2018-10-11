#pragma once

#include <iostream>
#include "ChessPieceType.h"

namespace TicTacToe
{
    class Chessboard
    {
    private:
        int chessboard[3][3];

        char NextChessPiece(int rowNumber, int columnNumber) const;

    public:
        Chessboard();
        ~Chessboard();

        bool AddChessPiece(int rowNumber, int columnNumber, ChessPieceType chessPieceType);

        friend std::ostream & operator<<(std::ostream & os, const Chessboard & chessboard);
    };
}
