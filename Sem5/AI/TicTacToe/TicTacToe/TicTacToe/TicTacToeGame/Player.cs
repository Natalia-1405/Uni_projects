using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TicTacToe.TicTacToeGame
{
    public class Player
    {
        public string Name { get; set; }
        public char Symbol { get; set; }  // np. 'X' lub 'O'

        public Player(string name, char symbol)
        {
            Name = name;
            Symbol = symbol;
        }
    }
}
