using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using TicTacToe.TicTacToeGame;

namespace TicTacToe
{
    public partial class Form1 : Form
    {
        private Game game;
        private Button[,] buttons;

        public Form1()
        {
            InitializeComponent();
            StartNewGame(10, 10); // przykładowa plansza 10x10
        }

        private void StartNewGame(int rows, int cols)
        {
            game = new Game(rows, cols, "Gracz 1", "Gracz 2");
            buttons = new Button[rows, cols];

            this.Controls.Clear();
            int buttonSize = 40;

            for (int r = 0; r < rows; r++)
            {
                for (int c = 0; c < cols; c++)
                {
                    Button btn = new Button
                    {
                        Location = new Point(c * buttonSize, r * buttonSize),
                        Size = new Size(buttonSize, buttonSize),
                        Font = new Font(FontFamily.GenericSansSerif, 16),
                        Tag = new Point(r, c)
                    };
                    btn.Click += Btn_Click;
                    buttons[r, c] = btn;
                    this.Controls.Add(btn);
                }
            }

            this.ClientSize = new Size(cols * buttonSize, rows * buttonSize);
        }

        private void Btn_Click(object sender, EventArgs e)
        {
            Button btn = sender as Button;
            Point p = (Point)btn.Tag;

            if (!game.MakeMove(p.X, p.Y)) return;

            btn.Text = game.CurrentPlayer.Symbol.ToString();

            if (game.CheckWin())
            {
                MessageBox.Show($"{game.CurrentPlayer.Name} wygrał!");
                StartNewGame(game.Board.Rows, game.Board.Columns);
                return;
            }

            if (game.IsDraw())
            {
                MessageBox.Show("Remis!");
                StartNewGame(game.Board.Rows, game.Board.Columns);
                return;
            }

            game.SwitchPlayer();
        }
    }
}
    

