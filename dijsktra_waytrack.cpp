#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
using namespace std;

const int N=1e5+1;
int n,m;
ll dis[N];
int pa[N];
bool vis[N];
vector<pii>adj[N];
priority_queue<pii,vector<pii>,greater<pii>>pq;

void root(int x){
    if(pa[x])root(pa[x]);
    cout << x << ' ';
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    for(int i=2; i<=n; i++)dis[i]=LLONG_MAX;
    pq.push({0,1});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(pii wv:adj[u]){
            ll w=wv.first;
            int v=wv.second;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pa[v]=u;
                pq.push({dis[v],v});
            }
        }
    }
    cout << '\n';
    root(n);
    cout << '\n' << dis[n];

    return 0;
}