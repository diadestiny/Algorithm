#include<iostream>
#include<algorithm>
using namespace std;
int dp[1010];
const int mod = 100007;
int main(){
    int n;
    cin>>n;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=0;
        for(int j=i-1;j>=0;j-=2){
            dp[i]+=dp[j];
            dp[i]%=mod;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}

