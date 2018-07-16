/**
BOJ 15903 카드 합체 놀이
Author : TAMREF
Complexity : O((n+m)lg n)
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

priority_queue<ll,vector<ll>,greater<ll>> q;

int n, m;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    ll x, y, ans = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        q.push(x);
        ans += x;
    }
    for(int i = 0; i < m; i++){
        x = q.top(); q.pop();
        y = q.top(); q.pop();
        ans += (x+y);
        q.push(x+y);
        q.push(x+y);
    }
    cout << ans << '\n';
}