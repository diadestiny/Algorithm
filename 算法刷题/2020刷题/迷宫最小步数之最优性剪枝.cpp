#include<iostream>
#include<string>
using namespace std;
string maze[110];
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
bool vis[110][110];
bool f=false;//默认false
int ans=1000000000; //int(32) 最大 2147483647
int n,m;
void dfs(int x,int y,int step){
    if(step>=ans){
        return;
    }
    if(maze[x][y]=='T'){
        f=true;
        ans=step;//step<ans恒成立
        return;
    }
    vis[x][y]=true;
    for(int i=0;i<4;i++){
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(tx>=0&&tx<n&&ty>=0&&ty<m&&!vis[tx][ty]&&maze[tx][ty]!='*'){
            dfs(tx,ty,step+1);
        }
    }
    vis[x][y]=false; //找出路径所有解，必须取消标记。
}
int main(){
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=0;i<n;i++){
       cin>>maze[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j]=='S'){
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
// 3 4
// S**.
// ....
// ***T