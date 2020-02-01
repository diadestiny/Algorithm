#include<cstdio>
int n;
int f(int x){
    if(x==n){
        return 1;
    }else{
        return (f(x+1)+1)*2;
    }
}
int main(){
    scanf("%d",&n);
    printf("%d",f(1));
    return 0;
}