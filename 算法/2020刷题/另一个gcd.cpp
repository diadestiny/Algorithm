#include<cstdio>
int gcd(int x,int y){
    if(y==0) return x;
    else{
        return gcd(y,x%y);
    }
}
int main(){
    int x,y;
    int t;
    scanf("%d",&t);
    while(t--){
    scanf("%d%d",&x,&y);
    printf("%d",gcd(x,y));
    }
    return 0;
}