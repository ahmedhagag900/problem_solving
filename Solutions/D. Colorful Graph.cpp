//handle: zoro500
//problem link:http://codeforces.com/problemset/problem/246/D



#include <bits/stdc++.h>

using namespace std;

const int M=1e5+9;
const long long N=2e18+9;

int n,m;

vector<int> graph[M];
set<int> nodeColors[M];
int vis[M];
int colors[M];


void dfs(int node)
{
    vis[node]=1;
    for(int i=0;i<graph[node].size();++i)
    {
        if(colors[node]!=colors[graph[node][i]])
            nodeColors[colors[node]].insert(colors[graph[node][i]]);
        if(!vis[graph[node][i]])
            dfs(graph[node][i]);


    }
}


int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&colors[i]);
    while(m--)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=n;++i)
        if(!vis[i])
            dfs(i);
    int maxi=0;
    int ans=M;
    for(int i=1;i<=n;++i)
    {
        if(nodeColors[colors[i]].size()>maxi)
        {
            maxi=nodeColors[colors[i]].size();
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(nodeColors[colors[i]].size()==maxi)
        {
            ans=min(ans,colors[i]);
        }
    }
    cout<<ans<<endl;

    return 0;
}
