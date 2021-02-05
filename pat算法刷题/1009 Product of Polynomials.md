```cpp
#include<bits/stdc++.h>
using namespace std;

double a[1005],b[1005];
double c[2005];
int n,m;
int main(){
    cin>>n;
    //double temp;
    int t;
    for(int i=0;i<n;i++){
        cin>>t>>a[t];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>t>>b[t];
    }
    for(int i=0;i<1001;i++){
        if(a[i]==0){
            continue;
        }
        for(int j=0;j<1001;j++){
            if(b[j] == 0) continue;
            
            c[i+j] += a[i]*b[j];
           // cout<<i<<" "<<j<< " " <<a[i]<<" "<<b[j]<<" "<<c[i+j]<<endl;
        }
    }
    int ct = 0;
    for(int i=2002;i>=0;i--){
        if(i < 0) break; 
        if(c[i]){
            ct++;
            
        }
    }
   cout<<ct;
     for(int i=2002;i>=0;i--){
         if(i < 0) break; 
        if(c[i]){
           cout<<" "<<i<<" ";
            printf("%.1lf",c[i]);
        }
    }
    return 0;
}
```

