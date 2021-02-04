```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m;
int d[505][505];
bool st[505];
int v[505] ;
int main(){
    cin>>n>>m;
    memset(d,0xf,sizeof(d));
    
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        d[a][b] = min(d[a][b],c);
    }
    
    memset(v,0xf,sizeof(v));//按字节初始化
    v[1] = 0;
    for(int i=1;i<=n;i++){
        //寻找最小下标
        int inx = 0;
        for(int j=1;j<=n;j++){
            if(!st[j] && v[j]<v[inx]){
                inx = j;
            }
        }
        st[inx] = 1;
        for(int j=1;j<=n;j++){
            if(!st[j]){
                v[j] = min(v[j],v[inx]+d[inx][j]);
            }
        }
    }
    if(v[n]==0x0f0f0f0f){
        cout<<"-1";
    }else{
        cout<<v[n];
    }
    return 0;
}
```

