using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LabiryntX
{
    public enum CellType
    {
        Empty,
        MainPath,
        Start,
        End,
        Fake
    }

    public class Maze
    {
        public const int Size = 12;
        public const int CellSize = 100;

        public CellType[,] Grid = new CellType[Size, Size];
        private Random rand = new Random();

        public Maze()
        {
            Generate();
        }

        private void Generate()
        {
            for (int x = 0; x < Size; x++)
                for (int y = 0; y < Size; y++)
                    Grid[x, y] = CellType.Empty;

            GenerateMainPath();
            GenerateFakeBranches();

            Grid[0, 0] = CellType.Start;
            Grid[11, 11] = CellType.End;
        }

        private void Mark(params Point[] cells)
        {
            foreach (Point p in cells)
                Grid[p.X, p.Y] = CellType.MainPath;
        }

        private void GenerateMainPath()
        {
            Mark(
                new Point(1, 0), new Point(2, 0), new Point(3, 0),
                new Point(3, 1), new Point(3, 2), new Point(3, 3), new Point(3, 4),
                new Point(4, 4), new Point(5, 4), new Point(6, 4),
                new Point(7, 4), new Point(7, 5), new Point(7, 6),
                new Point(8, 6), new Point(9, 6),
                new Point(9, 7), new Point(9, 8),
                new Point(10, 8), new Point(10, 9), new Point(10, 10), new Point(10, 11),
                new Point(11, 11)
            );
        }

        private void GenerateFakeBranches()
        {
            for (int i = 0; i < 10; i++)
            {
                int x = rand.Next(Size);
                int y = rand.Next(Size);

                if (Grid[x, y] == CellType.Empty)
                    Grid[x, y] = CellType.Fake;
            }
        }

        public Color GetColor(CellType t)
        {
            if (t == CellType.Start || t == CellType.End)
                return Color.White;
            if (t == CellType.MainPath)
                return Color.Red;
            if (t == CellType.Fake)
                return Color.Orange;

            return Color.Green;
        }
    }
}
