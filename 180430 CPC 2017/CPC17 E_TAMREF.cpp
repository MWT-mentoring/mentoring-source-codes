/*
CPC 2017 #E. BOJ #14730
Author : TAMREF
Time Complexity : O(N)
Space Complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        ans+=(a*b%mod);
    }
    cout<<ans<<endl;
}