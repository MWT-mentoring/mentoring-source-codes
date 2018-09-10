/*

Contest name : USACO 2018 January
Problem ID (in the contest) : Gold #3
Task name : Stamp Painting
BOJ ID : #15588

Author : TAMREF
Time Complexity : O(N)
Space Complexity : O(N) (It can be optimized to O(K), how can it be achieved?)

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int mx = 1e6 + 5;

ll S[mx];
ll ans = 1, d, m, n, k;

int main(){
    cin >> n >> m >> k;
    ll p = 1; S[0] = 1;
    for(int i = 1; i < k; i++){
        p = p * m % mod;
        S[i] = (S[i-1] + p) % mod;
    }
    for(int i = k; i <= n; i++){
        S[i] = m * S[i-1] - (m-1) * S[i-k];
        S[i] = (S[i] % mod + mod) % mod;
    }
    for(int i = 1; i <= n; i++) ans = ans * m % mod;

    cout << ((ans - S[n] + S[n-1]) % mod + mod) % mod << endl;
}
