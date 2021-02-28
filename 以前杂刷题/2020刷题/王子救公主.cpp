#include<stdio.h>
char mp[105][105];
bool vis[105][105][2];
int n,m,x,y;
bool ans;
void dfs(int x,int y,int d){
    if(x<0||x>=n||y<=0||y>=m||vis[x][y][d]||mp[x][y]=='#') return;
    vis[x][y][d]=true;
    dfs(x-(2-d),y,d);
    dfs(x+(2-d),y,d);
    dfs(x,y-(2-d),d);
    dfs(x,y+(2-d),d);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",mp[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]=='w'){
                x=i;
                y=j;
            }
        }
    }
    dfs(x,y,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j]=='g'){
                x=i;
                y=j;
            }
        }
    }
    dfs(x,y,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j][0]&&vis[i][j][1]){
               ans=true;
                break;
            }
        }
    }
    if(ans){
        printf("yes\n");
    }else{
        printf("no\n");
    }
    return 0;
}