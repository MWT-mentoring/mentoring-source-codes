/*
CPC 2017 #H. BOJ #14733
Author : TAMREF
Time Complexity : O(N lg N)
Space Complexity : O(N)
*/

#include <bits/stdc++.h>
#define va first
#define vb second

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mx = 3005;
const int ms = 16387; //Segment tree size; least 2^k - like integer greater than 2 * mx

int q;

struct line{
    ll x, y[2];
    int v;
} tam[2*mx];

struct SegTree{
    ll len[mx + mx];
    ll lens[ms], sum[ms];
    int cnt[ms];
    int n;
    int tmp, ul, ur, uv;

    ll init(int now, int s, int e){

        cnt[now] = 0;
        sum[now] = 0;

        if(s==e){
            lens[now] = len[s];
            return lens[now];
        }

        int m = (s+e)/2;
        int le = now<<1, ri = now<<1|1;
        lens[now] = init(le,s,m) + init(ri,m+1,e);
        return lens[now];
    }

    void upd(int now, int s, int e){
        int le = now<<1, ri = now<<1|1;
        int m = (s+e)>>1;

        if(s > ur || e < ul) return;

        if(ul <= s && e <= ur){
            cnt[now] += uv;
        }else{
            if(s!=e){
                upd(le,s,m);
                upd(ri,m+1,e);
            }
        }
        if(!cnt[now]){
            if(s==e) sum[now] = 0;
            else sum[now] = sum[le] + sum[ri];
        }
        else sum[now] = lens[now];
    }

    void update(int l, int r, int v){
        ul = l; ur = r; uv = v;
        upd(1,0,n-1);
    }

    void ini(){
        memset(cnt,0,sizeof(cnt));
        memset(lens,0,sizeof(lens));
        init(1,0,n-1);
    }
} S;

ll cy[mx+mx];
void init(){
    int n;
    cin>>q;
    n = S.n = q;

    for(int i=0;i<n;i++){
        cin>>tam[2*i].x>>tam[2*i].y[0];
        cin>>tam[2*i+1].x>>tam[2*i].y[1];

        tam[2*i].v = 1;
        tam[2*i+1].v = -1;

        cy[2*i] = tam[2*i].y[0];
        cy[2*i+1] = tam[2*i].y[1];
    }

    sort(cy,cy+2*n);
    int m = unique(cy,cy+2*n)-cy;

    for(int i=0;i<m-1;i++){
        S.len[i] = cy[i+1] - cy[i];
    }

    for(int i=0;i<n;i++){
        for(int b=0;b<2;b++){
            tam[2*i].y[b] = lower_bound(cy,cy+m,tam[2*i].y[b]) - cy - b;
            tam[2*i+1].y[b] = tam[2*i].y[b];
        }
    }

    sort(tam,tam+2*n,[](line &u, line &v){
        return u.x<v.x;
    });

    S.n = --m;
    S.ini();
}

ll query(){
    q *= 2;
    ll ans = 0;
    for(int i=0;i<q;i++){
        ans += S.sum[1] * (tam[i].x - tam[i?i-1:0].x);
        S.update(tam[i].y[0],tam[i].y[1],tam[i].v);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    cout<<query()<<endl;
}