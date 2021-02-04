```cpp
#include<bits/stdc++.h>

using namespace std;

int m;
string a[100],b[100],c[100];

int main(){
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    int early,later = 0;
    for(int i=1;i<m;i++){
        string ts = b[i];
        bool q1 = stoi(ts.substr(0,2))< stoi(b[early].substr(0,2));
        
        bool q2 = stoi(ts.substr(0,2)) == stoi(b[early].substr(0,2))
        && ts.substr(3,2)< b[early].substr(3,2);
        
        bool q3 = stoi(ts.substr(0,2)) == stoi(b[early].substr(0,2))
        && stoi(ts.substr(3,2)) == stoi(b[early].substr(3,2))
        && stoi(ts.substr(6,2)) < stoi(b[early].substr(6,2));
        if(q1 || q2 ||q3){
            early = i;
        }
        
        ts = c[i];
        q1 = stoi(ts.substr(0,2))> stoi(c[later].substr(0,2));
        
        q2 = stoi(ts.substr(0,2)) == stoi(c[later].substr(0,2))
        && ts.substr(3,2) > c[later].substr(3,2);
        
        q3 = stoi(ts.substr(0,2)) == stoi(c[later].substr(0,2))
        && stoi(ts.substr(3,2)) == stoi(c[later].substr(3,2))
        && stoi(ts.substr(6,2)) > stoi(c[later].substr(6,2));
        if(q1 || q2 ||q3){
            later = i;
        }
        
    }
    cout<<a[early]<<" "<<a[later];
    return 0;
}

```

