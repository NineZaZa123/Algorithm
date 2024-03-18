#include<bits/stdc++.h>
#define double long double
#define pii pair<double,double>
using namespace std;

const int N=1e5+1;
int n;
pii arr[N];

double solve(int l,int r){
    if(l==r)return 1000000;
    if(l+1==r){
        double x1=arr[l].first,y1=arr[l].second;
        double x2=arr[r].first,y2=arr[r].second;
        return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
    }
    int mid=(l+r)/2;
    double d=min(solve(l,mid),solve(mid+1,r));
    int ll=max(l-16,1);
    int rr=min(r+16,n);
    for(int i=ll; i<=rr; i++){
        if(i==mid)continue;
        double x1=arr[mid].first,y1=arr[mid].second;
        double x2=arr[i].first,y2=arr[i].second;
        d=min(d,sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))));
    }
    return d;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr+1,arr+n+1,[&](pii a,pii b){
        if(a.second==b.second)return a.first<b.first;
        else return a.second<b.second;
    });
    cout << solve(1,n);

    return 0;
}

/*
6
2 3
12 30
40 50
5 1
12 10
3 4
*/
