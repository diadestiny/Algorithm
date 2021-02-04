#include<iostream>
using namespace std;
//最少移动次数 最少移动体力(移动第n号盘子需要n点体力)
//f[n]=f[n-1]+1+f[n-1]; 总次数
//g[n]=g[n-1]+n+g[n-1]; 总体力
long long f[65],g[65];
int main(){
    int n;
    cin>>n;
    f[1]=1;
    g[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=2*f[i-1]+1;
    }
    for(int i=2;i<=n;i++){
        g[i]=2*g[i-1]+i;
    }
    cout<<f[n]<<" "<<g[n]<<endl;
    return 0;
}