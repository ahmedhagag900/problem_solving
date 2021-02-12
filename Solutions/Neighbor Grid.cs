//Problem Link: https://codeforces.com/contest/1375/problem/B
//Handel: zoro500

using System.Text;
using System;
using System.Collections;

namespace codeforces
{
    class Program
    {

        private static bool vaildCell(int i,int j,int n,int m)
        {
            return (i < n && i >= 0 && j < m && j >= 0);
        }
        private static int Count_Neighbours(int i,int j, int[,] grid){
            int num_of_neighbours=0;
            int n=grid.GetLength(0);
            int m=grid.GetLength(1);
                    
            int[,] dimensions = new int[,] { { i, j + 1 }, { i, j - 1 }, { i - 1, j }, { i + 1, j } };
            for (int idx = 0; idx < 4; ++idx)
            {
                if (vaildCell(dimensions[idx, 0], dimensions[idx, 1], n, m))
                {
                    num_of_neighbours += (grid[dimensions[idx, 0], dimensions[idx, 1]] > 0) ? 1 : 0;
                }
            }

            return num_of_neighbours;
        }

        private static void AssignNeighoubers(int i,int j,int neighbours,int[,] grid)
        {
            int n = grid.GetLength(0);
            int m = grid.GetLength(1);
            int[,] dimensions = new int[,] { { i, j + 1 }, { i, j - 1 }, { i - 1, j }, { i + 1, j } };
            for (int idx = 0; idx < 4; ++idx)
            {
                if (neighbours > 0)
                {
                   if (vaildCell(dimensions[idx, 0], dimensions[idx, 1], n, m))
                   {
                       grid[dimensions[idx, 0], dimensions[idx, 1]] += (grid[dimensions[idx, 0], dimensions[idx, 1]] == 0) ? 1 : 0;
                       neighbours--;
                   }
                }
            } 
        }

        static void Main(string[] args)
        {
            int tc=Int32.Parse(Console.ReadLine());
            for(int idx=0;idx<tc ;++idx){

                string[] n_m = Console.ReadLine().Split(new char[0],StringSplitOptions.RemoveEmptyEntries);
                int n = Int32.Parse(n_m[0]);
                int m = Int32.Parse(n_m[1]);
                
                int[,] grid=new int[n,m];

                for(int i=0;i<n;++i){
                    string[] line = Console.ReadLine().Split(new char[0], StringSplitOptions.RemoveEmptyEntries);
                    for(int j=0;j<m;++j){
                        grid[i, j] = Int32.Parse(line[j]);
                    }
                }


                for (int i=0;i<n;++i){
                    for(int j=0;j<m;++j){
                        if (grid[i, j] == 0) continue; 
                        int num_of_neighnours = Count_Neighbours(i, j, grid);
                        if (num_of_neighnours < grid[i, j])
                            AssignNeighoubers(i, j, grid[i, j], grid);
                    }
                }
                for (int i = 0; i < n; ++i)
                {
                    for (int j = 0; j < m; ++j)
                    {
                        if (grid[i, j] == 0) continue;
                        int num_of_neighnours = Count_Neighbours(i, j, grid);
                        if (num_of_neighnours > grid[i, j])
                            grid[i, j] += (num_of_neighnours - grid[i, j]);
                    }
                }

                bool ok=true;
                for(int i=0;i<n&&ok;++i){
                    for(int j=0;j<m&&ok;++j){
                        if(grid[i,j]==0) continue;
                        if(grid[i,j]!=Count_Neighbours(i,j,grid))
                            ok=false;
                    }
                }

                if(ok){
                    Console.WriteLine("YES");
                    for(int i=0;i<n;++i){
                        for(int j=0;j<m;++j){
                            Console.Write(grid[i,j]+" ");
                        }
                        Console.WriteLine();
                    }
                }else{
                    Console.WriteLine("NO");
                }
            }
        }
    }
}
