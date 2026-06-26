using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TicTacToe.TicTacToeGame
{
    public class Game
    {
        public Board Board { get; }
        public Player Player1 { get; }
        public Player Player2 { get; }
        public Player CurrentPlayer { get; private set; }
        public int WinCondition { get; } = 5; // 5 w linii

        public Game(int rows, int cols, string player1Name, string player2Name)
        {
            Board = new Board(rows, cols);
            Player1 = new Player(player1Name, 'X');
            Player2 = new Player(player2Name, 'O');
            CurrentPlayer = Player1;
        }

        public bool MakeMove(int row, int col)
        {
            if (!Board.IsCellEmpty(row, col)) return false;

            Board.PlaceSymbol(row, col, CurrentPlayer.Symbol);

            return true;
        }

        public void SwitchPlayer()
        {
            CurrentPlayer = CurrentPlayer == Player1 ? Player2 : Player1;
        }

        public bool CheckWin()
        {
            char symbol = CurrentPlayer.Symbol;
            int rows = Board.Rows;
            int cols = Board.Columns;

            for (int r = 0; r < rows; r++)
            {
                for (int c = 0; c < cols; c++)
                {
                    if (Board.Cells[r, c] != symbol) continue;

                    if (CheckDirection(r, c, 1, 0, symbol)) return true; // poziomo
                    if (CheckDirection(r, c, 0, 1, symbol)) return true; // pionowo
                    if (CheckDirection(r, c, 1, 1, symbol)) return true; // skos \
                    if (CheckDirection(r, c, 1, -1, symbol)) return true; // skos /
                }
            }

            return false;
        }

        private bool CheckDirection(int row, int col, int dRow, int dCol, char symbol)
        {
            int count = 0;
            for (int i = 0; i < WinCondition; i++)
            {
                int r = row + i * dRow;
                int c = col + i * dCol;
                if (r < 0 || r >= Board.Rows || c < 0 || c >= Board.Columns) return false;
                if (Board.Cells[r, c] != symbol) return false;
                count++;
            }
            return count == WinCondition;
        }

        public bool IsDraw() => Board.IsFull() && !CheckWin();
    }
}

