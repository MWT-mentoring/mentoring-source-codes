/*
CPC 2017 #D. BOJ #14729
Author : TAMREF
Time Complexity : O(N + X) (X : range of input number, 10^6 in this problem)
Space Complexity : O(X)
*/

#include <bits/stdc++.h>
using namespace std;
int cnt[100001];
int main(){
    int n; scanf("%d",&n);
    for(int i=0,a,b;i<n;i++){
        scanf("%d%*c%d",&a,&b);
        ++cnt[1000*a+b];
    }
    for(int i=0,c=0;c<7;i++){
        for(;cnt[i]&&c<7;--cnt[i]){
            printf("%d.%03d\n",i/1000,i%1000);
            ++c;
        }
    }
    return 0;
}