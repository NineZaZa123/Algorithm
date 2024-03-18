#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
using namespace std;

const int N=1e5+1;
int n,m;
ll ans;
ll dis[N];
bool vis[N];
vector<pii>adj[N];
queue<int>q;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=2; i<=n; i++)dis[i]=LLONG_MAX;
    for(int i=1; i<=m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    q.push(1);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(vis[u])continue;
        vis[u]=true;
        ans+=dis[u];
        int v;
        ll mn=LLONG_MAX;
        for(pii wi:adj[u]){
            ll w=wi.first;
            int i=wi.second;
            if(vis[i])continue;
            dis[i]=min(dis[i],w);
            if(dis[i]<mn){
                v=i;
                mn=dis[i];
            }
        }
        q.push(v);
    }
    cout << ans;

    return 0;
}

/*
5 10
1 5 3
1 2 1
2 5 5
1 3 2
2 3 4
2 4 1
3 4 3
4 5 2
1 4 2
3 5 1
*/