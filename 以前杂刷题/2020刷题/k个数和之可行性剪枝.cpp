#include<iostream>
using namespace std;
int n,k,sum,ans;
int a[40];
void dfs(int i,int cnt,int s){
    if(cnt>k) return;//无效枝叶1
    if(s>sum) return;//无效枝叶2
    if(i==n){
        if(cnt==k&&s==sum){
            ans++;
        }
        return;
    }
    dfs(i+1,cnt,s);
    dfs(i+1,cnt+1,s+a[i]);
}
int main(){
    n=30;
    k=8;
    sum=200;
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    dfs(0,0,0);
    cout<<ans<<endl;
    return 0;
}
