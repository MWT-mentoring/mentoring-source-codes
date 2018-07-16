/**
BOJ 2336 굉장한 학생
Author : TAMREF (With Indexed Tree)
Complexity : O(nlgn)
**/

#include <bits/stdc++.h>
using namespace std;

const int o = 524288;
const int inf = 1e8;

struct stu{
    int r[3];
} tam[o];

struct Idxtree{
    int a[o+o];

    Idxtree(){
        init();
    }

    void init(){
        for(int x = o ; x > 1 ; x >>= 1){
            for(int y = x ; y < x + x ; y += 2){
                a[y] = a[y^1] = a[y>>1] = inf;
            }
        }
    }

    int rmq(int s, int e){
        s += o, e += o;
        int m = min(a[s], a[e]);
        while(s <= e){
            m = min({m, a[s], a[e]});
            (++s)>>=1;
            (--e)>>=1;
        }
        return m;
    }

    void upd(int i, int v){
        i += o;
        a[i] = v;
        for(;i>1;i>>=1){
            a[i>>1] = min(a[i], a[i^1]);
        }
    }
} I;

int n;

void input(){
    cin>>n;
    int st;
    for(int t=0;t<3;t++){
        for(int i=1;i<=n;i++){
            cin>>st;
            tam[st].r[t] = i;
        }
    }
    sort(tam + 1, tam + n+1, [](stu& u, stu& v){return u.r[0]<v.r[0];});
}

void query(){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(I.rmq(1,tam[i].r[2]) >= tam[i].r[1]) ++cnt;
        I.upd(tam[i].r[2],tam[i].r[1]);
    }
    cout<<cnt<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    query();
}
