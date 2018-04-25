/*

Contest name : USACO 2018 January
Problem ID (in the contest) : Bronze #2, Silver #1
Task name : Rental Service
BOJ ID : #15590

Author : TAMREF
Time Complexity : O(nlgn + mlgm + rlgr)
Space Complexity : O(n + m + r)

*/

#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;

const int mx = 1e5 + 5;

vector<pii> shop;
ll Milk = 0;
void addmilk(ll M){
    if(shop.empty()) return;
    for(;!shop.empty() && M;){
        if(M < shop.back().vb){
            shop.back().vb -= M;
            Milk += (ll)shop.back().va * M;
            break;
        }
        Milk += (ll)shop.back().va * shop.back().vb;
        M -= shop.back().vb;
        shop.pop_back();
    }
}

ll C[mx], R[mx];
int n, m, r;

void input(){
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) cin >> C[i];
    pii p;
    for(int i = 0; i < m; i++){
        cin >> p.second >> p.first;
        shop.push_back(p);
    }
    for(int i = 1; i <= r; i++) cin >> R[i];

    sort(C+1, C+n+1, greater<ll>());
    sort(R+1, R+r+1, greater<ll>());
    for(int i = 1; i <= r; i++) R[i] += R[i-1];
    sort(shop.begin(), shop.end());
}

void pro(){
    ll ans = R[min(n,r)], lans;
    for(int k = 1; k <= n; k++){
        addmilk(C[k]);
        lans = Milk + R[min(n-k,r)];
        //printf("k = %d, Milk = %lld, rent = %lld, lans = %lld\n",k,Milk, R[min(n-k,r)], lans);
        ans = max(ans, lans);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    pro();
}
