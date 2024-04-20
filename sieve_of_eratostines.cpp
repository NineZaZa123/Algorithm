#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=101;
bitset<N>prime;
vector<ll>p;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    for(ll i=3; i<N; i+=2){
        if(!prime[i]){
            p.push_back(i);
            for(ll j=i*i; j<N; j+=i*2){
                prime[j]=true;
            }
        }
    }
    for(ll i:p)cout << i << ' ';

    return 0;
}