```cpp
#include<iostream>


using namespace std;
int n,q;
int a,b,pre,tmax;
int p[10005];
int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    for(int i=0;i<10005;i++) p[i] = i;
    cin>>n;
    while(n--){
        cin>>a;
        for(int i=0;i<a;i++){
             cin>>b;
             if(i==0) pre = b;
             p[find(b)] = find(pre);
             if(b>tmax) tmax = b;
        }
    }
    int ans = 0;
    for(int i=1;i<=tmax;i++){
        if(p[i] == i) ans++; //集合数
    }
    cout<<ans<<" "<<tmax<<endl;
    cin>>q;
    
    while(q--){
        cin>>a>>b;
        auto x = find(a)==find(b);
        if(x == 1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
```

