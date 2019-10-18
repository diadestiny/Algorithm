#include <iostream>
#include <stack>
using namespace std;
 
const int maxm=100,maxn=100;
int MAZE[maxm][maxn],m,n;
typedef pair<int,int> P;
void input(){
    cin>>m>>n;
    int t;
    for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>t;
        MAZE[i][j]=t;
    }
    }
}
P Move(P curr){
    P next = curr;
    int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};//记录移动的四个方位
    for (int i = 0; i < 4;i++){
        int x=curr.first+dx[i],y=curr.second+dy[i];
        if(MAZE[x][y]==0&& MAZE[x][y] != 2 && x>=0 && x<m && y>=0 && y<n){
            next.first = x;
            next.second = y;
            MAZE[x][y] = 2;
            return next;
        }
    }
    return curr;
}
void dfs(){
    stack<P> Path;
    P curr,nex;
    curr.first=0;curr.second=0;
    Path.push(curr);
    MAZE[0][0]=2;
    while(!Path.empty()){
        curr=Path.top();
        nex=Move(curr);
        if(!(curr.first==nex.first&&curr.second==nex.second)){Path.push(nex);}
        else{Path.pop();}
        if(nex.first==m-1&&nex.second==n-1){
            P route[Path.size()];
            int z=0;
            while(!Path.empty()){
                curr=Path.top();
                route[z++]=curr;
                Path.pop();
            }
            for(int k=z-1;k>=0;k--){
                cout<<"("<<route[k].first<<","<<route[k].second<<")";
                if(k%5==0) cout<<endl;
                if(k) cout<<"->";
            }
            return ;
        }
    }
    cout<<"noPath"<<endl;
}
int main(){
    input();
    dfs();
    return 0;
}