#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5+1;
int n;
ll ans;
int arr[N];

void msort(int l,int r){
    if(l==r)return;
    int mid=(l+r)/2;
    msort(l,mid);
    msort(mid+1,r);
    int lsz=mid-l+1;
    int rsz=r-mid;
    int arrl[lsz+1],arrr[rsz+1];
    for(int i=l; i<=mid; i++)arrl[i-l+1]=arr[i];
    for(int i=mid+1; i<=r; i++)arrr[i-mid]=arr[i];
    for(int idx=l,lidx=1,ridx=1; lidx<=lsz||ridx<=rsz;){
        if(lidx<=lsz&&ridx<=rsz){
            if(arrl[lidx]<=arrr[ridx]){
                arr[idx++]=arrl[lidx++];
            }
            else{
                ans+=mid-(l+lidx-1)+1;
                arr[idx++]=arrr[ridx++];
            }
        }
        else if(lidx<=lsz)arr[idx++]=arrl[lidx++];
        else arr[idx++]=arrr[ridx++];
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    msort(1,n);
    cout << ans;

    return 0;
}