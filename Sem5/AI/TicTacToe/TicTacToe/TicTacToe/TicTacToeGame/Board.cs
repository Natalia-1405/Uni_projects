using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TicTacToe.TicTacToeGame
{
    public class Board
    {
        public int Rows { get; }
        public int Columns { get; }
        public char[,] Cells { get; }

        public Board(int rows, int columns)
        {
            Rows = rows;
            Columns = columns;
            Cells = new char[rows, columns];

            // inicjalizacja pustymi znakami
            for (int r = 0; r < rows; r++)
                for (int c = 0; c < columns; c++)
                    Cells[r, c] = ' ';
        }

        public bool IsCellEmpty(int row, int col) => Cells[row, col] == ' ';

        public void PlaceSymbol(int row, int col, char symbol)
        {
            if (IsCellEmpty(row, col))
                Cells[row, col] = symbol;
            else
                throw new InvalidOperationException("Cell is not empty!");
        }

        public bool IsFull()
        {
            for (int r = 0; r < Rows; r++)
                for (int c = 0; c < Columns; c++)
                    if (Cells[r, c] == ' ')
                        return false;
            return true;
        }
    }
}

