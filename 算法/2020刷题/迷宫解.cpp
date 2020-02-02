#include<cstdio>
char s[10][10];
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
bool vis[10][10];
bool f=false;//默认false
int ans=0; //int(32) 最大 2147483647
int n,m;
void dfs(int x,int y){
    vis[x][y]=true;
    // if(f){
    //     return;
    // }
    if(s[x][y]=='e'){
        f=true;
        ans++;
        return ;
    }
    for(int i=0;i<4;i++){
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(tx>=0&&tx<n&&ty>=0&&ty<m&&!vis[tx][ty]&&s[tx][ty]!='#'){
            dfs(tx,ty);
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
            if(s[i][j]=='s'){
                x=i;
                y=j;
            }
        }
    }
    dfs(x,y);
    if(f){
        printf("%d",ans);
        //printf("Yes\n");
    }else{ 
        printf("No\n");
    }
    return 0;
}
// 5 5
// s####
// .####
// .####
// .####
// ....e