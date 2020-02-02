#include<cstdio>
char s[10][10];
int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
bool vis[10][10];
bool f=false;//默认false
void dfs(int x,int y){
    vis[x][y]=true;
    if(f){
        return;
    }
    if(s[x][y]=='T'){
        f=true;
        return ;
    }
    for(int i=0;i<8;i++){
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        if(tx>=0&&tx<10&&ty>=0&&ty<9&&!vis[tx][ty]&&s[tx][ty]!='#'){
            dfs(tx,ty);
        }
    }
    //vis[x][y]=false; //如果是找出路径或者所有解，需要取消标记。
}
int main(){
    int x,y;
    for(int i=0;i<10;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            if(s[i][j]=='S'){
                x=i;
                y=j;
            }
        }
    }
    dfs(x,y);
    if(f){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
// .#....#S#
// ..#.#.#..
// ..##.#..#
// ......##.
// ...T.....
// ...#.#...
// ...#.....
// ...###...
// .........
// .##......