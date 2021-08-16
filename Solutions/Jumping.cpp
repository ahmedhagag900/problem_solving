/******************************************************************************
 
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/
// proplem link : https://codeforces.com/gym/101147/problem/E
//handle : zoro500
#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
int tc,n;
map<int,vector<int>> graph;
int ans[100005];
int vis[100005];
void bfs(int src){
    std::queue<int> nodes;
    nodes.push(src);
    ans[src]=0;
    while(!nodes.empty()){
        int parent=nodes.front();
        nodes.pop();
        vis[parent]=1;
        for(int i=0;i<graph[parent].size();++i)
        {
            if(vis[graph[parent][i]]!=1&&ans[graph[parent][i]]==-1)
            {
                nodes.push(graph[parent][i]);
                ans[graph[parent][i]]=ans[parent]+1;
            }
        }
    }
}
 
 
int main()
{
    freopen("jumping.in", "r", stdin);
    scanf("%d",&tc);
    while(tc--){
        memset(vis,0,sizeof(vis));
        memset(ans,-1,sizeof(ans));
        scanf("%d",&n);
        for(int i=0,x;i<n;++i)
        {
            scanf("%d",&x);
            if(i+x<n)graph[i+x].push_back(i);
            if(i-x>=0)graph[i-x].push_back(i);
        }
        bfs(n-1);
        for(int i=0;i<n;++i)printf("%d\n",ans[i]);
        graph.clear();
       
    }
 
    return 0;
}
