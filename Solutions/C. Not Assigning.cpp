//handle:zoro500
//problem link: https://codeforces.com/contest/1627/problem/C

#include <bits/stdc++.h>
 
using namespace std;
 
const int M=1e5+9;
const long long N=1e18+9;
const int MOD=1000000007;
 
 
int tc,n;
int deg[M];
vector<vector<int> > g;
vector<pair<int,int> > edges;
map<pair<int,int>,int> sol;
void dfs(int node,int parent,int c,map<pair<int,int>,int>& sol)
{
    for(int i=0;i<g[node].size();++i)
    {
        if(g[node][i]!=parent)
        {
            dfs(g[node][i],node,c+1,sol);
        }
        int u=node;
        int v=g[node][i];
        if(c&1^1)
        {
            sol[{u,v}]=2;
            sol[{v,u}]=2;
        }else
        {
 
            sol[{u,v}]=3;
            sol[{v,u}]=3;
        }
    }
}
 
 
int main()
{
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        g.resize(n+1);
        for(int i=0;i<n-1;++i)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
            edges.push_back({u,v});
            deg[u]++;
            deg[v]++;
 
        }
        bool hasSol=true;
        int stNode=-1;
        for(int i=1;i<=n;++i)
        {
            if(deg[i]>2)hasSol=false;
            if(deg[i]==1)stNode=i;
        }
        if(hasSol)
        {
            dfs(stNode,-1,0,sol);
            for(int i=0;i<edges.size();++i)
            {
                auto pp=edges[i];
                cout<<sol[pp]<<" ";
            }
            puts("");
        }else
        {
            puts("-1");
        }
        memset(deg,0,sizeof(int)*(n+1));
        edges.clear();
        sol.clear();
        for(int i=0;i<n+1;++i)
            g[i].clear();
 
    }
 
 
    return 0;
}
