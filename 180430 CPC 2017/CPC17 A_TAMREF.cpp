/*
CPC 2017 #A. BOJ #14726
Author : TAMREF
Time Complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;
int t[16];
int main(){
    int T;
    for(scanf("%d",&T);T--;){
        for(int i=0;i<16;i++){
            scanf("%1d",&t[i]);
            if((i&1)==0){
                t[i]*=2;
                t[i]=(t[i]/10)+(t[i]%10);
            }
        }
        int s=0;
        for(int i=0;i<16;i++) s+=t[i];
        puts(s%10?"F":"T");
    }
}