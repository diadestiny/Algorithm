#include<cstdio>
char s[105][105];
int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int n,m,x,y;
void dfs(int x,int y,int step){
    if(step>3) return;
    if(x<0||x>=n||y<0||y>=m){
        return;
    }
    s[x][y]='#';
    for(int i=0;i<8;i++){
        int tx=x+dir[i][0];
        int ty=y+dir[i][1];
        dfs(tx,ty,step+1);
    }

}
int main(){
    
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            s[i][j]='.';
        }
    }
    dfs(x-1,y-1,0);
    for(int i=0;i<n;i++){
        printf("%s\n",s[i]);
    }
    return 0;
}