#include<cstdio>
#include<algorithm>
using namespace std;
int a[205];
int b[205];
int ans[205];
bool vis[205];
int n;
//次数函数
int f(int x){
    if(x>n){
        return 0;
    }
    if(vis[x]){
        return ans[x];
    }
    vis[x]=true;
    return ans[x]=min(f(x+a[x]),f(x+b[x]))+1;
}
int main(){

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    printf("%d",f(1));
    return 0;
}