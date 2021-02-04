#include<iostream>
using namespace std;
int n,k,sum,ans;
int a[40];
void dfs(int i,int cnt,int s){
    if(i==n){
        if(cnt==k && s==sum){
            ans++;
        }
        return;
    }
    dfs(i+1,cnt,s);
    dfs(i+1,cnt+1,s+a[i]);
}
int main(){
    cin>>n>>k>>sum;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ans=0;
    dfs(0,0,0);
    cout<<ans<<endl;

    return 0;
}
// 5 3 9
// 1 2 3 4 5 