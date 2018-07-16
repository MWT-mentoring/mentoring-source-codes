/**
BOJ 15900 나무 탈출
Author : TAMREF
Complexity : O(n)
**/

#include <bits/stdc++.h>
using namespace std;

const int mx = 5e5 + 5;

vector<int> G[mx];

int n;

int dfs(int x, int p, int d){
    int ret = 0, flag = 0;
    for(int &u : G[x]){
        if(u == p) continue;
        flag = 1;
        ret += dfs(u,x,d+1);
    }
    return flag ? ret : d;
}

void init(){
    cin >> n;
    for(int i = 1, a, b; i < n; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    init();
    puts(dfs(1,0,0) & 1 ? "Yes" : "No");
}