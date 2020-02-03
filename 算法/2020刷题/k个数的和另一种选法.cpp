#include<iostream>
using namespace std;
int n,k,sum,ans;
int a[105];
bool xuan[105];
//参数st强制规定搜索顺序从前往后
void dfs(int s,int cnt,int st){
    if(s==sum && cnt==k){
        ans++;
        return;
    }for(int i=st;i<n;i++){
        if(!xuan[i]){
            xuan[i]=1;
            dfs(s+a[i],cnt+1,i+1);
            xuan[i]=0;
        }
    }
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