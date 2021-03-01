//problem link:https://codeforces.com/problemset/problem/1492/B
//Handle: zoro500

using System;
using System.Collections;
namespace codeforces
{
    public class Program
    {
        public static void Main(string[] args)
        {
            int[] arr=new int[100009];
            Stack st=new Stack();
            int tc=Int32.Parse(Console.ReadLine());
            while(tc>0){
                int n=Int32.Parse(Console.ReadLine());
                string line=Console.ReadLine();
                string[] input=line.Split(' ');
                for(int i=0;i<n;++i)
                    arr[i]=Int32.Parse(input[i]);
                
                int start=0;
                int end=0;
                int comp = arr[0];
                for(int i=0;i<n;++i){
                    if(comp<arr[i]){
                        st.Push(new Tuple<int,int>(start,end));
                        start = i;
                        end = i;
                        comp = arr[i];
                    }else if(i!=0){
                        end++;
                    }
                }
                st.Push(new Tuple<int, int>(start, end));
                foreach(Tuple<int,int> x in st){
                    for (int i = x.Item1; i <= x.Item2; ++i)
                        Console.Write(arr[i] + " ");
                }
                Console.WriteLine();
                st.Clear();
                --tc;
            }
        }
        
    }
}
