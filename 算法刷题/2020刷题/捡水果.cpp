#include<iostream>
#include<algorithm>
using namespace std;
int f[110][110];
int dp[110][110];
int ans=-1;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>f[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(i==1&&j==1){
                dp[1][1]=f[1][1];
            }else if(j==1||j==i){
                dp[i][j]=dp[i-1][j]+f[i][j];
            }else{
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+f[i][j];
            }
            if(i==n){
                cout<<dp[i][j]<<endl;
                ans=max(dp[i][j],ans);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
// 4
// 3
// 1 2
// 6 2 3
// 3 5 4 1