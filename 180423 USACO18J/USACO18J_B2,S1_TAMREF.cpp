/*

Contest name : USACO 2018 January
Problem ID (in the contest) : Bronze #2, Silver #1
Task name : Blocked Billboard II
BOJ ID : #15593, #15589

Author : TAMREF
Time Complexity : O(nlgn)
Space Complexity : O(n)

*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int mx = 1e5 + 5;

int lft[mx], rgt[mx];
struct itv{
    int s, e, i;
    bool operator< (itv x){
        return s < x.s;
    }
} tam[mx];
int n;

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tam[i].s >> tam[i].e;
        tam[i].i = i;
    }
    sort(tam,tam+n);
}

bool prepro(){
    int rmt = -1;
    for(int i = 0; i < n; i++){
        if(rmt >= tam[i].e) return true;
        rmt = max(rmt, tam[i].e);
    }
    return false;
}

int pro1(){
    int rmt = -1;
    int len = 0;
    for(int i = 0; i < n; i++){
        if(tam[i].s > rmt){
            rmt = tam[i].s;
        }
        if(tam[i].e > rmt){
            len += tam[i].e - rmt;
            rmt = tam[i].e;
        }
    }
    //printf("%d\n",len);
    return len;
}

int pro2(){
    int rmt = -1;
    for(int i = 0; i < n; i++){
        if(tam[i].s >= rmt){
            rmt = tam[i].s;
        }
        lft[tam[i].i] = rmt;
        if(tam[i].e > rmt){
            rmt = tam[i].e;
        }
    }
    int lmt = 1e9 + 5;
    sort(tam,tam+n,[](itv u, itv v){return u.e > v.e;});
    for(int i = 0; i < n; i++){
        if(tam[i].e <= lmt){
            lmt = tam[i].e;
        }
        rgt[tam[i].i] = lmt;
        if(tam[i].s < lmt){
            lmt = tam[i].s;
        }
    }
    int loss = 1e9 + 5;
    for(int i = 0; i < n; i++){
        //printf("%dth - [%d, %d]\n",i,lft[i],rgt[i]);
        loss = min(loss, rgt[i] - lft[i]);
    }
    return max(0,loss);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    cout << pro1() - (prepro() ? 0 : pro2()) << '\n';
}
