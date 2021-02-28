#include<iostream>
#include<queue>
#include<string>
using namespace std;
string maze[110];
bool vis[110][100];
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int ans=1000000000; //int(32) 最大 2147483647
int n,m;
struct node
{
    int x,y,d;
    node(int a, int b, char c) :x(a), y(b), d(c){}
};

bool in(int x,int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

int bfs(int sx,int sy){
    queue<node> q;
    q.push(node(sx,sy,0));
    vis[sx][sy]=true;
    while(!q.empty()){
        node now=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx=now.x+dir[i][0];
            int ty=now.y+dir[i][1];
            if(in(tx,ty)&&maze[tx][ty]!='*'&&!vis[tx][ty]){
                if(maze[tx][ty]=='T'){
                    return now.d+1;
                }else{
                    vis[tx][ty]=true;
                    q.push(node(tx,ty,now.d+1));
                }
            }
        }
    }
    return -1;
}
int main(){
    cin>>n>>m;
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
    cout<<bfs(x,y)<<endl;
   
    return 0;
}
// 5 6
// ....S*
// .**...
// .*..*.
// *..**.
// .T....
