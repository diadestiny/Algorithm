```cpp
#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int a,b;
int f = 0;
int main(){
    
    cin>>a>>b;
    int c = a + b;
    if(c<0) {f = 1;c = -c;};
    
    if(c==0){
        cout<<0;
        return 0;
    }
    
    while(c!=0){
        v.push_back(c%1000);
        c = c/1000;
    }
    
    if(f) cout<<"-";
    for(int i=v.size()-1;i>=0;i--){
        
        if(i!=v.size()-1){
            if(v[i]<10){
                cout<<"00";
            }
            else if(v[i]<100){
                cout<<"0";
            }
        }
        cout<<v[i];
        if(i!=0)cout<<",";
    }
    return 0;
}
```





