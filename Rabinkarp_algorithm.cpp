#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+1,MOD=1e9+7;
ll hshtxt=0,hshpat=0,h=1,b=10;
ll pw[N];
string txt,pat;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> txt >> pat;
    for(int i=1; i<pat.size(); i++)h=(h*b)%MOD;
    for(int i=0; i<pat.size(); i++){
        hshtxt=(hshtxt*b+txt[i])%MOD;
        hshpat=(hshpat*b+pat[i])%MOD;
    }
    if(hshpat==hshtxt)cout << 0 << ' ';
    // for(int i=0; i+pat.size()<txt.size(); i++){ 
    //     hshtxt=((((hshtxt-(txt[i]*h)%MOD)+MOD)%MOD*b)%MOD+txt[i+pat.size()])%MOD;
    //     if(hshtxt==hshpat)cout << i+1 << ' ';
    // }
    for(int i=0; i+pat.size()<txt.size(); i++){ 
        hshtxt=(hshtxt-(txt[i]*h)%MOD)*b+txt[i+pat.size()];
        if(hshtxt==hshpat)cout << i+1 << ' ';
    }

    return 0;
}
