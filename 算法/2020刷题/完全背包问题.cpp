#include<iostream>
#include<cstring>
using namespace std;
// int dp[21][1010];
int dp[1010];
int w[21],c[21];
int main(){
    int N,V;
    cin>>N>>V;
    for(int i=1;i<=N;i++){
        cin>>w[i]>>c[i];
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=0;j<=V;j++){
    //         if(j>=c[i]){
    //             dp[i][j]=max(dp[i][j-c[i]]+w[i],dp[i-1][j]);
    //         }else{
    //             dp[i][j]=dp[i-1][j];
    //         }
    //     }
    // }
    // cout<<dp[N][V]<<endl;
    
    // 优化空间复杂度
    for(int i=1;i<=N;i++){
        for(int j=c[i];j<=V;j++){
            dp[j]=max(dp[j-c[i]]+w[i],dp[j]);
        }
    }
    cout<<dp[V]<<endl;
   
    return 0;
}
// 5 10
// 2 1
// 3 5
// 2 5
// 3 4
// 4 3
