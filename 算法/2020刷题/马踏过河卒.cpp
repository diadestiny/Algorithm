#include<iostream>
using namespace std;
int dir[8][2]={1,2,1,-2,2,1,2,-1,-1,2,-1,-2,-2,-1,-2,1};
int dp[30][30];
bool d[30][30]; 
int main(){
    int n,m,cx,cy;
    //n,m是棋盘大小，cx,cy是马的位置
    cin>>n>>m>>cx>>cy;
    d[cx][cy]=true;
    for(int i=0;i<8;i++){
        int tx=cx+dir[i][0];
        int ty=cy+dir[i][1];
        if(tx>=0&&tx<n&&ty>=0&&ty<m){
            d[tx][ty]=true;
        }
    }
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(d[i][j]==false){
                if(i){
                 dp[i][j]+=dp[i-1][j];
                } 
                if(j){
                 dp[i][j]+=dp[i][j-1];
                }
            }
            
        }
    }
    cout<<dp[n-1][m-1];
     return 0;
 }