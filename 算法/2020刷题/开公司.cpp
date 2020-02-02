#include<cstdio>
int task[15][15];
bool used[15];
int ans;
int n;
void dfs(int x,int t){
    if(x==n){
        if(t<ans){
            ans=t;
        }
        return;
    }
    for(int i=0;i<n;i++){
        if(!used[i]){
            used[i]=true;
            dfs(x+1,t+task[x][i]);
            used[i]=false;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&task[i][j]);
        }
    }
    ans=20000;
    dfs(0,0);
    printf("%d",ans);
    return 0;
}
// 6
// 10 11 12 11 9 11
// 11 9 10 13 11 12
// 12 10 11 10 13 9
// 9 14 9 10 10 11
// 10 10 9 11 12 11
// 10 7 10 10 10 8