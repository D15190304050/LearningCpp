#include "Chessboard.h"

namespace TicTacToe
{
    Chessboard::Chessboard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                chessboard[i][j] = 0;
        }
    }

    Chessboard::~Chessboard()
    {
        
    }

    char Chessboard::NextChessPiece(int rowNumber, int columnNumber) const
    {
        switch (chessboard[rowNumber][columnNumber])
        {
        case 0:
            return ' ';
        case 1:
            return 'X';
        case 2:
            return 'O';
        default:
            return '\0';
        }
    }

    bool Chessboard::AddChessPiece(int rowNumber, int columnNumber, ChessPieceType chessPieceType)
    {
        if (chessboard[rowNumber][columnNumber] == ChessPieceType::Empty)
        {
            chessboard[rowNumber][columnNumber] = chessPieceType;
            return true;
        }
        else
            return false;
    }


    std::ostream& operator<<(std::ostream& os, const Chessboard& chessboard)
    {
        for (int i = 0; i < 3; i++)
        {
            os << "-------" << std::endl;

            for (int j = 0; j < 3; j++)
                os << "|" << chessboard.NextChessPiece(i, j);

            os << "|" << std::endl;
        }

        os << "-------";

        return os;
    }

}
