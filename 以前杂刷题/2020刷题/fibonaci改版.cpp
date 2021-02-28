#include<cstdio>
int n,a,b,p;
int ans[105];
bool vis[105];
// int fib(int n){
//     if(n==1||n==2) return 1%p;
//     else return (a*fib(n-1))%p+(b*fib(n-2))%p;
// }  
int fib(int n){
    if(n==1||n==2) return 1%p;
    else {
        if(vis[n]==0){
            vis[n]=1;
            ans[n]= (a*fib(n-1))%p+(b*fib(n-2))%p;
        }
        return ans[n];
    }
}  
int main(){
    scanf("%d%d%d%d",&n,&a,&b,&p);
    printf("%d",fib(n));
    return 0;
}