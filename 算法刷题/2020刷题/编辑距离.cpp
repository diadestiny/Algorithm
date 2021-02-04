#include<iostream>
#include<string>
//两个字符串 模糊匹配 编辑距离
using namespace std;
int dp[110][110];
string a,b;
int main(){
    cin>>a>>b;
    int lena=a.size();
    int lenb=b.size();
    for(int i=1;i<=lena;i++){
        dp[i][0]=i;
    }
    for(int i=1;i<=lenb;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=lena;i++){
        for(int j=1;j<=lenb;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
            }
        }
    }
    cout<<dp[lena][lenb]<<endl;
    return 0;
}
// abcd
// acef