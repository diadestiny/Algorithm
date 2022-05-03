```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int n,m;

vector<int> path;
vector<vector<int> > ans;
int vis[1001];
void dfs(int c){
    if(ans.size() == m){
        return;
    }
    if(c == n){
        ans.push_back(path);
        return ;
    }
    for (int i = 0; i < n; i ++ ){
         if(!vis[i]){
              path.push_back(i);
              vis[i] = 1;
              dfs(c+1);
              path.pop_back();
              vis[i] = 0;
         }
        
    }
    
}

int main()
{
    cin>>n>>m;
    dfs(0);
    for(int j=0;j<ans[m-1].size();j++){
        cout<<ans[m-1][j];
    }
    
    return 0;
}
```

