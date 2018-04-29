/*
CPC 2017 #C. BOJ #14728
Author : TAMREF
Time Complexity : O(NT)
Space Complexity : O(N+T)
*/

#include <bits/stdc++.h>
using namespace std;
int dp[10005], tp[10005];
int bj[105], ti[105];
int n,t;
int main(){
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++) scanf("%d%d",&ti[i],&bj[i]);
    for(int i=0;i<n;i++){
        fill(tp,tp+t+1,0);
        for(int j=1;j+ti[i]<=t;j++){
            if(dp[j]) tp[j+ti[i]]=dp[j]+bj[i];
        }
        tp[ti[i]]=bj[i];
        for(int j=1;j<=t;j++) dp[j]=max(dp[j],tp[j]);
    }
    printf("%d\n",*max_element(dp,dp+t+1));
}