#include<cstdio>
char map[105][105];
bool vis[105][105];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int n,m;
int ans=0;
bool in(int x,int y){
    return 0<=x && x<n && 0<=y && y<m;
}
void dfs(int x,int y){
    vis[x][y]=true;
    for(int i=0;i<4;i++){
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(in(tx,ty)&&map[tx][ty]=='#'&&!vis[tx][ty]){
            dfs(tx,ty);
        }
    }
    return;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
         scanf("%s",map[i]);
    } 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]=='#'&&!vis[i][j]&&in(i,j)){
                dfs(i,j);
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}

// 5 6
// .#....
// ..#...
// ..#..#
// ...##.
// .#....