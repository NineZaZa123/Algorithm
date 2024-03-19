#include<bits/stdc++.h>
using namespace std;

const int N=101;
int q,n,m;
int dp[N][N];
string a,b;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> a >> b;
    a="x"+a;
    b="x"+b;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j]=0;
            if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[n][m] << '\n';

    return 0;
}
