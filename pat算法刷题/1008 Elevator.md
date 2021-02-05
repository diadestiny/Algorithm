```cpp
// O(1)复杂度
#include <bits/stdc++.h>
using namespace std;
int n;
int ct = 0;
int ot;
int a[1001];
int main(){
    cin>>n;
    int f = 1;
    while(n--){
        int t;
        cin>>t;
        if(f) {
            f = 0;
            ct+=t*6+5;
            ot = t;
        }
        else{
            if(t>ot){
                ct+=(t-ot)*6+5;
            }else if(t == ot){
                ct +=5;
            }else{
                ct+=(ot-t)*4+5;
            }
            ot = t;
        }
        
    }
    cout<<ct;
    return 0;
}
```

