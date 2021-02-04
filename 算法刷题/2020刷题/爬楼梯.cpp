#include<iostream>
#include<algorithm>
using namespace std;
int dp[1010];
const int mod = 100007;
int main(){
    int n;
    cin>>n;
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}

