/*

Contest name : USACO 2018 January
Problem ID (in the contest) : Gold #2
Task name : Cow at Large (Gold)
BOJ ID : #15587

Author : TAMREF
Time Complexity : O(N)
Space Complexity : O(N)

*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 5;

int dRoot[mx], dLeaf[mx];
vector<int> G[mx];

int n, k, ans;

void input(){
    cin >> n >> k;
    for(int i = 1, a, b; i < n; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dLeaf[0] = mx + 1;
    dRoot[0] = -1;
}

void dfs1(int x, int p){
    dRoot[x] = dRoot[p] + 1;
    dLeaf[x] = mx + 1;
    bool isLeaf = true;
    for(int &u : G[x]){
        if(u == p) continue;
        isLeaf = false;
        dfs1(u,x);
        dLeaf[x] = min(dLeaf[x], dLeaf[u] + 1);
    }
    if(isLeaf) dLeaf[x] = 0;
}

void dfs2(int x, int p){
    dLeaf[x] = min(dLeaf[x], dLeaf[p] + 1);
    for(int &u : G[x]){
        if(u == p) continue;
        dfs2(u,x);
    }
}

void dfs3(int x, int p){
    if(p && dLeaf[x] <= dRoot[x] && dLeaf[p] > dRoot[p]) ++ans;
    for(int &u : G[x]){
        if(u == p) continue;
        dfs3(u,x);
    }
}

void debug(){
    for(int i = 1; i <= n; i++){
        printf("dRoot[%d] = %d, dLeaf[%d] = %d\n",i,dRoot[i],i,dLeaf[i]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    input();
    dfs1(k,0);
    dfs2(k,0);
    dfs3(k,0);
    cout << ans << endl;
}
