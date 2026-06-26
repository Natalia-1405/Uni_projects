using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LabiryntX
{
    public class MainForm : Form
    {
        private Maze maze = new Maze();
        private Random rand = new Random();

        public MainForm()
        {
            this.DoubleBuffered = true;
            this.WindowState = FormWindowState.Maximized;
            this.Text = "LABIRYNTX";
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);

            int mazeWidth = Maze.Size * Maze.CellSize;
            int mazeHeight = Maze.Size * Maze.CellSize;

            int offsetX = (ClientSize.Width - mazeWidth) / 2;
            int offsetY = (ClientSize.Height - mazeHeight) / 2;

            DrawMaze(e.Graphics, offsetX, offsetY);
        }

        private void DrawMaze(Graphics g, int ox, int oy)
        {
            for (int x = 0; x < Maze.Size; x++)
                for (int y = 0; y < Maze.Size; y++)
                {
                    Rectangle rect = new Rectangle(
                        ox + x * Maze.CellSize,
                        oy + y * Maze.CellSize,
                        Maze.CellSize,
                        Maze.CellSize);

                    Brush b = new SolidBrush(maze.GetColor(maze.Grid[x, y]));
                    g.FillRectangle(b, rect);
                    b.Dispose();

                    g.DrawRectangle(Pens.Black, rect);

                    DrawWalls(g, rect);
                }
        }

        private void DrawWalls(Graphics g, Rectangle r)
        {
            Color[] colors = { Color.Yellow, Color.Blue, Color.Orange, Color.Purple };
            Pen p = new Pen(colors[rand.Next(colors.Length)], 4);

            g.DrawRectangle(p, r);
            p.Dispose();
        }
    }
}
