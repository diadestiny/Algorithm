#include<cstdio>
int bian[15];
int n,sum=0;
bool f;
bool vis[15];
void dfs(int p,int s,int st){
    if(f) return;
    if(p==3){
        f=true;
        return;
    }
    if(s==sum/3){
        dfs(p+1,0,0);
    }
    for(int i=st;i<n;i++){
        if(!vis[i]){
            vis[i]=true;
            dfs(p,s+bian[i],i+1);
            vis[i]=false;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&bian[i]);
        sum+=bian[i];
    }
    if(sum%3!=0){
        printf("no\n");
    }else{
        dfs(0,0,0);
        if(f){
            printf("yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}