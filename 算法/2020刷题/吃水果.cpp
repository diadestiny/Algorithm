#include<cstdio>
char s[105][105];
bool vis[105][105];
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int n,m;
int ans=-1;
int num;
bool in(int x,int y){
    return 0<=x && x<n && 0<=y && y<m;
}
void dfs(int x,int y){
   //printf("%d %d\n",x,y);
   num++;
   vis[x][y]=true;
   for(int i=0;i<4;i++){
       int tx=x+dir[i][0];
       int ty=y+dir[i][1];
       if(s[tx][ty]=='#'&&in(tx,ty)&&!vis[tx][ty]){
           //num++;
           dfs(tx,ty);
       }
   }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='#'&&in(i,j)&&!vis[i][j]){
                //num=1;
                num=0;
                dfs(i,j);
                if(num>ans){
                    ans=num;
                }
            }
        }
    }
    if(ans!=-1){
        printf("%d\n",ans);
    }else{
        printf("No\n");
    }
    return 0;
}
// 5 7
// .#...##
// ..#..##
// ..#..##
// #..####
// .#..#..