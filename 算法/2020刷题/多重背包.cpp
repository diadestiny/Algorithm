#include<iostream>
#include<cstring>
using namespace std;
// int dp[21][1010];
int dp[1010];
int w[21],c[21],n[21];
int main(){
    int N,V;
    cin>>N>>V;
    for(int i=1;i<=N;i++){
        cin>>w[i]>>c[i]>>n[i];
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=0;j<=V;j++){
    //         for(int k=0;k<=n[i];k++){
    //             if(j>=c[i]*k){
    //                 dp[i][j]=max(dp[i-1][j-c[i]*k]+w[i]*k,dp[i-1][j]);
    //             }
    //             //当k=0时，dp[i][j]=dp[i-1][j]相当于01背包的else部分
    //         }
           
    //     }
    // }
    // cout<<dp[N][V]<<endl;
    
    //优化空间复杂度
    for(int i=1;i<=N;i++){
        for(int j=V;j>=0;j--){
            for(int k=0;k<=n[i];k++){
                if(j>=c[i]*k){
                    dp[j]=max(dp[j-c[i]*k]+w[i]*k,dp[j]);
                }
            }
        }
    }
    cout<<dp[V]<<endl;
   
    return 0;
}
// 5 10
// 2 1 2
// 3 5 3
// 2 5 1
// 3 4 2
// 4 3 8