#include<bits/stdc++.h>
using namespace std;

const int N=1001;
int n,w;
int val[N],we[N];
int dp[N];
int ans;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> w;
    for(int i=1; i<=n; i++)cin >> val[i];
    for(int i=1; i<=n; i++)cin >> we[i];
    ans=0;
    for(int i=0; i<=w; i++)dp[i]=0;
    for(int i=1; i<=n; i++){
        for(int j=w; j>=0; j--){
            if(j<we[i])continue;
            dp[j]=max(dp[j],dp[j-we[i]]+val[i]);
            ans=max(ans,dp[j]);
        }
    }
    cout << ans << '\n';
    
    return 0;
}
