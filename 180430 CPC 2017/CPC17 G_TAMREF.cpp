/*
CPC 2017 #G. BOJ #14732
Author : TAMREF
Time Complexity : O(NXY)
Space Complexity : O(XY)
*/

#include <bits/stdc++.h>
using namespace std;
int b[502][502];
int main(){
    int n; scanf("%d",&n);
    for(int i=0,a,bb,c,d;i<n;i++){
        scanf("%d%d%d%d",&a,&bb,&c,&d);
        for(int x=a;x<c;x++){
            for(int y=bb;y<d;y++) b[x][y]=1;
        }
    }
    int ans=0;
    for(int i=0;i<=500;i++) for(int j=0;j<=500;j++) ans+=b[i][j];
    printf("%d\n",ans);
}