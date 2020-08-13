// Problem link: https://codeforces.com/contest/1303/problem/C?mobile=false
// user : zoro500 


#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define ppii pair<pii,int>

using namespace std;

const int M=1e5+9;
const int MOD=1e9+7;
const long long N=1e12+9;

string s;

map<char,int>mp;
set<pii> st;
vector<int>adj[27];
bool vis[27];
char arr[27];
int dfs_node=-1;
bool fr[27];
void dfs(int node){
    vis[node]=true;
    for(auto child:adj[node]){
        if(!vis[child])dfs(child);
    }
    fr[arr[node]-'a']=true;
    cout<<arr[node];
}

bool dfs(int node,int parent){
    if(adj[node].size()>2)return false;
    if(adj[node].size()<=1)dfs_node=node;
    vis[node]=true;
    bool ans=1;
    for(auto child:adj[node]){
        if(child!=parent){
            if(vis[child]==true)return false;
            else ans&=dfs(child,node);
        }
    }
    return ans;
}

int tc;
int main()
{
    scanf("%d",&tc);
    while(tc--){
        cin>>s;
        int idx=0;
        for(int i=0;s[i];++i){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=idx;
                arr[idx++]=s[i];
            }
        }
        for(int i=1;s[i];++i){
            int u=mp[s[i]];
            int v=mp[s[i-1]];
            if(st.find({u,v})==st.end()&&st.find({v,u})==st.end()){
                st.insert({u,v});
                st.insert({v,u});
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
        if(dfs(0,-1)){
            puts("YES");
            memset(vis,0,sizeof(vis));
            dfs(dfs_node);
            for(int i=0;i<26;++i){
                if(fr[i])continue;
                char res=i+'a';
                printf("%c",res);
            }
            printf("\n");
        }
        else
            puts("NO");
        mp.clear();
        st.clear();
        memset(vis,0,sizeof(vis));
        memset(arr,0,sizeof(arr));
        memset(fr,0,sizeof(fr));
        dfs_node=-1;
        for(int i=0;i<27;++i)adj[i].clear();
    }
    return 0;
}
