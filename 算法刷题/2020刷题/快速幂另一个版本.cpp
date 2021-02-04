#include<cstdio>
long long x,y,p;
long long f(long long x,long long y){
    if(y==0){
        return 1%p;
    }else if(y%2==0){
        long long temp=f(x,y/2)%p;
        return temp * temp % p;
    }else {
        long long temp=f(x,y/2)%p;
        return temp * temp % p * x % p;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
    scanf("%lld%lld%lld",&x,&y,&p);
    printf("%lld",f(x,y));
    }
    return 0;
}