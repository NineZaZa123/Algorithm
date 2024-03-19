#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;

const int N=101;
int n;
int idx;
pii arr[N];
ll dp[N][N];

ll solve(int l,int r){
    if(l==r)return 0;
    if(dp[l][r])return dp[l][r];
    ll ans=LLONG_MAX;
    for(int i=l; i<r; i++){
        ll mul=solve(l,i)+solve(i+1,r)+(arr[l].first*arr[i].second*arr[r].second);
        ans=min(ans,mul);
    }
    return dp[l][r]=ans;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    cin >> arr[1].first;
    idx=1;
    for(int i=2; i<=n; i++){
        cin >> arr[idx].second;
        arr[idx+1].first=arr[idx].second;
        idx++;
    }
    idx--;
    cout << solve(1,idx) << '\n';

    return 0;
}
