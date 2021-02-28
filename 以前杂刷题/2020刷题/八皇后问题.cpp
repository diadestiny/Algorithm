#include<iostream>
using namespace std;
int ans=0;
bool col[10],x1[20],x2[20];
bool check(int r,int i){
    return !col[i]&&!x1[r+i]&&!x2[r-i+8];
}
void dfs(int r){
    if(r==8) {
        ans++;
        return;
    }
    for(int i=0;i<8;i++){
        if(check(r,i)){
            col[i]=x1[r+i]=x2[r-i+8]=true;
            dfs(r+1);
            col[i]=x1[r+i]=x2[r-i+8]=false;//因为要搜索出所有解
        }
    }
}

int main(){
    dfs(0);
    cout<<ans<<endl;
    return 0;
}
