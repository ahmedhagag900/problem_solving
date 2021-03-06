//problem link:https://codeforces.com/contest/1492/problem/A
//Handle: zoro500

using System;
namespace codeforces
{
    public class Program
    {
        public static void Main(string[] args)
        {
            int tc=Int32.Parse(Console.ReadLine());
            while(tc>0){
                string line=Console.ReadLine();
                string[] input=line.Split(' ');
                long[] values=new long[input.Length];
                for(int i=0;i<input.Length;++i){
                    values[i]=Int64.Parse(input[i]);
                    if(i!=0){
                        long tmp=values[0]%values[i];
                        if(tmp!=0)
                            values[i]-=tmp;
                        else
                            values[i]=0;
                    }
                }
                long ans=Int64.MaxValue;
                for(int i=1;i<values.Length;++i){
                    if(values[i]<ans)ans=values[i];
                }
                Console.WriteLine(ans);
                --tc;
            }
        }
        
    }
}
