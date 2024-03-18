#include<bits/stdc++.h>
using namespace std;

int n,x;
int dp;
int ans=INT_MIN;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x;
        dp+=x;
        ans=max(ans,dp);
        if(dp<0)dp=0;
    }
    cout << ans;

    return 0;
}
