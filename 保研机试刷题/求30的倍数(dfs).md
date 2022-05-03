```c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<int> path;
long long mx = -1;
string num;
int vis[100001];
void dfs(int u){
    if(u == num.size()){
        long long res = 0;
        for(int j=0;j<path.size();j++){
            res = res * 10 + path[j];
        }
        if(res % 30 == 0 && res > mx){
            mx = res;
        }
        return;
    }
    for(int i=0;i<v.size();i++){
        if(!vis[i]){
            path.push_back(v[i]);
            vis[i] = 1;
            dfs(u+1);
            path.pop_back();
            vis[i] = 0;
        }
    }
}
int main()
{
   
    cin>>num;
    for(int i=0;i<num.size();i++) v.push_back(num[i]-'0');
    dfs(0);
    cout<<mx;
    
}
```





```cpp
#include <iostream>
#include <algorithm>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;

const int maxn=10005;
bool cmp(int x,int y){
    return x>y;
}
string s;
int a[maxn];
int main(){
    cin>>s;
    int sum=0;
    int flag=0;
    for(int i=0;i<s.size();i++){
        a[i]=s[i]-'0';
    }
    for(int i=0;i<s.size();i++){
        if(a[i]==0) flag=1;
        sum+=a[i];
    }
    if(sum%3!=0||flag==0){
        cout<<"-1"<<endl;
    }
    else{
        sort(a,a+s.size(),cmp);
        for(int i=0;i<s.size();i++){
            cout<<a[i];
        }
    }
}
```

