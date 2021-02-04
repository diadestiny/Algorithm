```cpp
#include<iostream>
#include<stdio.h>
#include<set>
#include<vector>

using namespace std;
int a;
int b;
double c;
vector<int> v1,v2,q;
vector<double> v3,v4,w;

set<int> s;
int count ;
int main(){
    cin>>a;
    while(a--){
        cin>>b>>c;
        v1.push_back(b);
        s.insert(b);
        v3.push_back(c);
    }
    cin>>a;
    while(a--){
        cin>>b>>c;
        v2.push_back(b);
        s.insert(b);
        v4.push_back(c);
    }
    
    count = s.size();
    int i = 0,j = 0;
    set<int>::iterator it = s.end();
    
    for(it--;;it--){
        double t = 0;
        if(v1[i] == *it){
            t+=v3[i];
            i++;
        }
        if(v2[j] == *it){
            t+=v4[j];
            j++;
        }
        if(t==0){
           count --;
        }
        else{
            q.push_back(*it);
            w.push_back(t);
        }
        if(it==s.begin()){
            break;
        }
    }
    cout<<count;
    for(int i=0;i<q.size();i++){
            printf(" %d %.1lf",q[i],w[i]);
        }
       
    return 0;
}
```





```cpp
#include <cstdio>
#include <iostream>

using namespace std;

double p[1010];

int main()
{
    int n,m;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        int b;//指数
        double a;//系数
        cin >> b >> a;
        p[b] += a;
    }
    cin >> m;
    for(int i = 0;i < m;i ++)
    {
        int b;
        double a;
        cin >> b >> a;
        p[b] += a;
    }
    int k = 0;
    for(int i = 0;i <= 1000;i ++)
        if(p[i] != 0)
            k ++;

    cout << k ;
    for(int i = 1000;i >= 0;i --)
    {
        if(p[i] != 0)
        {
            printf(" %d %.1lf",i,p[i]);
        }
    }

    return 0;
}

```

