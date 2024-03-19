#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=101,MOD=1e9+7;
int q,n,m;
ll dp[N][N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    dp[1][1]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1&&j==1)continue;
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=MOD;
        }
    }
    cout << dp[n][m] << '\n';

    return 0;
}
