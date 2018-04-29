/*
CPC 2017 #B. BOJ #14727
Author : TAMREF
Time Complexity : O(N)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, h, i, j, k;
ll ans;
stack<ll> tam;
stack<int> ding, pos;
int main(){
    //while(1)
    {
        scanf("%d",&N);
        ans=0;
        for(i=0;i<N;i++){
            scanf("%d",&h);
            while(!tam.empty() && tam.top()>h){
                ans = max(ans,tam.top()*(i-ding.top()));
                tam.pop(); ding.pop(); pos.pop();
            }
            tam.push(h);
            ding.push(ding.empty()?0:pos.top()+1);
            pos.push(i);
        }
        while(!tam.empty()){
            //printf("%lld %d\n",tam.top(),ding.top());
            ans = max(ans,tam.top()*(N-ding.top()));
            tam.pop(); ding.pop(); pos.pop();
        }
        printf("%lld\n",ans);
    }
}