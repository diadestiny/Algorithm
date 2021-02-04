```cpp
#include<bits/stdc++.h>
using namespace std;
int n,m;
int d[505][505];
bool st[505];
int v[505] ;
int ren[505];
int num[505],zdrs[505];
int t,e;
int main(){
    cin>>n>>m>>t>>e;
    for(int i=0;i<n;i++){
        cin>>ren[i];
    }
    memset(d,0x3f,sizeof(d));
    while(m--){
        int a,b;
        cin>>a>>b>>d[a][b];
        d[b][a] = d[a][b];
    }
    
    memset(v,0x3f,sizeof(v));//按字节初始化
    v[t] = 0;
    num[t] = 1;
    zdrs[t] = ren[t];
    for(int i=0;i<n;i++){
        //寻找最小下标
        int inx = -1;
        for(int j=0;j<n;j++){
            if(!st[j] && (inx == -1 ||v[j]<v[inx])){
                inx = j;
            }
        }
        st[inx] = 1;
        
        for(int j=0;j<n;j++){
            if(!st[j]){
                if(v[j] > v[inx]+d[inx][j] ){
                    v[j] = v[inx]+d[inx][j];
                    num[j] = num[inx];
                    zdrs[j] = zdrs[inx] + ren[j];
                }
                else if(v[j] == v[inx]+d[inx][j] ){
                    num[j] = num[inx]+num[j];
                    zdrs[j] = max(zdrs[j], zdrs[inx] + ren[j]);
                }
            }
        }
    }
    cout<<num[e]<<" "<<zdrs[e];
    return 0;
}
```

