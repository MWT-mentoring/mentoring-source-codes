/*
CPC 2017 #F. BOJ #14731
Author : TAMREF
Time Complexity : O(N lg K)
Space Complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll pow2(ll n){
    ll p=1,po=2;
    for(int d=0;d<33;d++){
        if(n>>d&1){
            p=(p*po)%mod;
        }
        po=(po*po)%mod;
    }
    return p;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        ans+=(a*b%mod)*pow2(b-1)%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
}
