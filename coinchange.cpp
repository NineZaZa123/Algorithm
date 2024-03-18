#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1;
int q,n,k;
int arr[N],dp[N];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> k >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    dp[0]=0;
    for(int i=1; i<=k; i++)dp[i]=1e9;
    for(int i=0; i<=k; i++){
        if(dp[i]==1e9)continue;
        for(int j=1; j<=n; j++){
            if(i+arr[j]>k)continue;
            dp[i+arr[j]]=min(dp[i+arr[j]],dp[i]+1);
        }
    }
    cout << dp[k] << '\n';

    return 0;
}