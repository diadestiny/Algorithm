#include<cstdio>
char s[10][10];
int dir[8][2]={{-1,0},{0,-1},{1,0},{0,1}};
bool vis[10][10];
bool f=false;//默认false
int ans=1000000000; //int(32) 最大 2147483647
int n,m;
void dfs(int x,int y,int step){
    vis[x][y]=true;
    // if(f){
    //     return;
    // }
    if(s[x][y]=='T'){
        f=true;
        if(ans>step){
            ans=step;
        }
        return ;
    }
    for(int i=0;i<4;i++){
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(tx>=0&&tx<n&&ty>=0&&ty<m&&!vis[tx][ty]&&s[tx][ty]!='*'){
            dfs(tx,ty,step+1);
        }
    }
    vis[x][y]=false; //找出路径所有解，必须取消标记。
}
int main(){
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='S'){
                x=i;
                y=j;
            }
        }
    }
    dfs(x,y,0);
    if(f){
        printf("%d",ans);
        //printf("Yes\n");
    }else{ 
        printf("No\n");
    }
    return 0;
}
