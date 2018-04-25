/*

Contest name : USACO 2018 January
Problem ID (in the contest) : Bronze #3
Task name : Blocked Billboard II
BOJ ID : #15594

Author : TAMREF
Time Complexity : O(n^3) (not optimal)
Space Complexity : O(n)

*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e2 + 5;

int cow[mx], scow[mx];
int bes = -1, n;

void init(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> cow[i];
    }
    n = unique(cow,cow+n) - cow;
    if(is_sorted(cow,cow+n)){
        puts("0");
        exit(0);
    }
    for(int i = 2; i <= n; i++){
        for(int s = 0; s + i <= n; s++){
            rotate(cow+s,cow+s+1,cow+s+i);
            if(is_sorted(cow,cow+n)){
                printf("%d\n",i-1);
                exit(0);
            }
            rotate(cow+s,cow+s+i-2,cow+s+i);
            if(is_sorted(cow,cow+n)){
                printf("%d\n",i-1);
                exit(0);
            }
            rotate(cow+s,cow+s+1,cow+s+i);
        }
    }
    assert(0);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
}
