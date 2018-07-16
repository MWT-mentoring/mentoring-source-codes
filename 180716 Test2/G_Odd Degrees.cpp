/**
BOJ 14554 Odd Degrees
Author : TAMREF
Complexity : O(E+V)
**/

#include <bits/stdc++.h>
using namespace std;

const int mxv = 50005, mxe = 1e5 + 5;

vector<int> G[mxv];
int n, m;
int vis[mxv], deg[mxv];

struct Edg{
    int u, v, save;
    Edg():u(0),v(0),save(1){}
    Edg(int u, int v, int save=1):u(u),v(v),save(save){}
    void toggle(){
        save = !save;
    }
    int oppo(int x){
        return u + v - x;
    }
} E[mxe];

void kill(){
    puts("-1");
    exit(0);
}

int dfs(int x){
    vis[x] = 1;
    int u;
    for(int &e : G[x]){
        u = E[e].oppo(x);
        if(vis[u]) continue;
        dfs(u);
        if(!deg[u]){
            E[e].toggle();
            deg[x] ^= 1;
            deg[u] ^= 1;
        }
    }
    return deg[x];
}

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> E[i].u >> E[i].v;
        G[ E[i].u ].push_back(i);
        G[ E[i].v ].push_back(i);
        deg[ E[i].u ] ^= 1;
        deg[ E[i].v ] ^= 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    input();
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(!dfs(i)) kill();
        }
    }
    vector<int> S;
    for(int i = 0; i < m; i++){
        if(E[i].save) S.push_back(i+1);
    }
    cout << S.size() << '\n';
    for(int &u : S) cout << u <<'\n';
}