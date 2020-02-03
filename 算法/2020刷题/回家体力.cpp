#include<iostream>
#include<algorithm>
using namespace std;
int a[110][110];
int dp[110][110];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    dp[1][1]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j==1)continue;
            else if(i==1) dp[i][j]=dp[i][j-1]+a[i][j];
            else if(j==1) dp[i][j]=dp[i-1][j]+a[i][j];
            else dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j];
        }
    }
    cout<<dp[n][n]<<endl;
    return 0;
}
// 3
// 0 3 4
// 6 2 5
// 5 4 3