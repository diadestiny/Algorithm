#include<cstdio>
#include<vector>
using namespace std;
vector<int> son[100005];
bool f[100005];
int ans[100005];
int dfs(int fa){
    int ret=0;
    for(int i=0;i<son[fa].size();i++){
        ret+=dfs(son[fa][i]);
    }
    ans[fa]=ret;
    return ret+1;
}
int main(){
    int n,x,y,u;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&x,&y);
        son[x].push_back(y);
        f[y]=true;
    }
    //找root
    for(int i=1;i<n;i++){
        if(!f[i]){
            u=i;
            break;
        }
    }
    dfs(u);
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}