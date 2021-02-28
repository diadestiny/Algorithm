#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int dp[10010],a[10010];
const int mod = 100010;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(dp,0,sizeof(dp));
    // memset只能初始化两个值，一个是0，一个是-1，当接收到的不是0和-1时，会自动初始化为任意值。
    int ans=0;
    for(int i=n;i>=1;i--){
       dp[i]=dp[i+a[i]]+1;
       ans=max(ans,dp[i]);
    }
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" "; 
    }
    
    return 0;
}
// 5
// 2 2 3 1 2