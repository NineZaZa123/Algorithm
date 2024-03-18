#include<bits/stdc++.h>
using namespace std;

int k=7;
vector<int>v={1,1,1,2,2,3};

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    map<int,int>dp;
    dp[0]=1;
    int ans=0;
    int sum=0;
    for(int i:v){
        sum+=i;
        ans+=dp[sum-k];
        dp[sum]++;
    }
    cout << ans;

    return 0;
}
