/*

Contest name : USACO 2018 January
Problem ID (in the contest) : Silver #3, Gold #1
Task name : MooTube
BOJ ID : #15591, #15586

Author : TAMREF
Time Complexity : O((N+Q)lg(N+Q))
Space Complexity : O(N+Q)

*/

#include <bits/stdc++.h>
using namespace std;

struct qry{
    int v, k, i;
};

struct edg{
    int u, v, k;
};

typedef pair<int,int> pii;
const int mx = 1e5 + 5;

int cpr[mx + mx];
int n, q, l, m;
int ans[mx];
qry task[mx];
edg E[mx];

vector<pii> t[mx + mx];
vector<qry> wrk[mx + mx];

int rep[mx];
int sz[mx];

int f(int x){return x == rep[x] ? x : rep[x] = f(rep[x]);}
void c(int x, int y){
    x = f(x), y = f(y);
    if(x != y){
        //printf("Connecting (%d,%d)\n",x,y);
        if(sz[x] < sz[y]) swap(x,y);
        sz[x] += sz[y];
        rep[y] = x;
    }
}

void init(){
    cin >> n >> q;
    iota(rep+1,rep+n+1,1);
    fill(sz+1,sz+n+1,1);
    for(int i = 0; i < n-1; i++){
        cin >> E[i].u >> E[i].v >> E[i].k;
        cpr[i] = E[i].k;
    }
    for(int i = 0; i < q; i++){
        cin >> task[i].k >> task[i].v;
        task[i].i = i;
        cpr[n - 1 + i] = task[i].k;
    }
    l = n + q - 1;
    sort(cpr,cpr+l);
    m = unique(cpr,cpr+l) - cpr;
    for(int i = 0; i < n - 1; i++){
        E[i].k = lower_bound(cpr,cpr+m,E[i].k) - cpr;
        t[ E[i].k ].emplace_back(E[i].u, E[i].v);
    }
    for(int i = 0; i < q; i++){
        task[i].k = lower_bound(cpr,cpr+m,task[i].k) - cpr;
        wrk[ task[i].k ].push_back( task[i] );
    }
}

void query(){
    for(int clk = m; clk--;){
        for(pii &p : t[clk]){
            //printf("Edge constructing step, clk = %d\n",cpr[clk]);
            c(p.first, p.second);
        }
        for(qry &w : wrk[clk]){
            ans[w.i] = sz[f(w.v)] - 1;
        }
    }
}

void output(){
    for(int i = 0; i < q; i++){
        cout << ans[i] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    query();
    output();
}
