#include<iostream>
#include<string>
using namespace std;
int n,m;
int vis[205][205];
char maze[205][205];
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
bool in(int a,int b){
    return 0<=a&&a<n&&0<=b&&b<m;
}
bool dfs(int x,int y){
    if(maze[x][y]=='T'){
        return true;
    }
    vis[x][y]=1;
    maze[x][y]='m';
    for(int i=0;i<4;i++){
    int tx=x+dir[i][0],ty=y+dir[i][1];
        if(in(tx,ty)&&!vis[tx][ty]&&maze[tx][ty]!='#'){
        if(dfs(tx,ty)) return true;
    }
    }
    vis[x][y]=0;
    maze[x][y]='.';
    return false;
}
// bool dfs(int x,int y){
//     if(maze[x][y]=='T'){
//         return true;
//     }
//     vis[x][y]=1;
//     maze[x][y]='m';
//     int tx=x-1,ty=y;
//     if(in(tx,ty)&&!vis[tx][ty]&&maze[tx][ty]!='#'){
//         if(dfs(tx,ty)) return true;
//     }
//     tx=x;ty=y-1;
//     if(in(tx,ty)&&!vis[tx][ty]&&maze[tx][ty]!='#'){
//         if(dfs(tx,ty)) return true;
//     }
//     tx=x+1;ty=y;
//     if(in(tx,ty)&&!vis[tx][ty]&&maze[tx][ty]!='#'){
//         if(dfs(tx,ty)) return true;
//     }
//     tx=x;ty=y+1;
//     if(in(tx,ty)&&!vis[tx][ty]&&maze[tx][ty]!='#'){
//         if(dfs(tx,ty)) return true;
//     }
//     vis[x][y]=0;
//     maze[x][y]='.';
//     return false;
// }
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }
    int x,y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j]=='S'){
                x=i;
                y=j;
            }
        }
    }
    if(dfs(x,y)){
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<maze[i][j];
        }
        cout<<endl;
        }
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}