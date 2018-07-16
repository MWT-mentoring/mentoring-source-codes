/**
BOJ 14554 The Other Way
Author : TAMREF
Complexity : O(ElgV)
**/

#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> li;
const ll inf=1e16, mod=1e9+9;
const int mx=100005;
priority_queue<li,vector<li>,greater<li>> pQ;
vector<ii> G[mx];
ll dist[mx],cnt[mx];
int n,m,s,e;
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>s>>e;
    for(int a,b,c;m--;){
        cin>>a>>b>>c;
        G[a].push_back({c,b});
        G[b].push_back({c,a});
    }
    fill(dist+1,dist+n+1,inf);
}
void dijk(){
    pQ.push({dist[s]=0,s}); cnt[s]=1;
    li t;
    while(!pQ.empty()){
        t=pQ.top(); pQ.pop();
        if(t.va>dist[t.vb]) continue;
        for(ii x : G[t.vb]){
            if(dist[x.vb]<t.va+x.va) continue;
            else if(dist[x.vb]>t.va+x.va){
                cnt[x.vb]=cnt[t.vb];
                pQ.push({dist[x.vb]=t.va+x.va,x.vb});
            }else{
                (cnt[x.vb]+=cnt[t.vb])%=mod;
            }
        }
    }
}
int main(){
    init();
    dijk();
    printf("%lld\n",cnt[e]);
}