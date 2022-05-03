```cpp
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10; // 无向图, 所以最大边数是2倍
int e[M], ne[M], h[N], idx;
int color[N];

bool ans = true;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int c) {
    if(ans == false) return ;
    color[u] = c;

    for(int i = h[u]; i != -1; i = ne[i]){
        if(color[e[i]] == c) {
            ans = false;
            return ;
        }else if(color[e[i]]==0){
            dfs(e[i],-c);
        }
    }

    return ;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);
    while (m --){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b,a);  // 无向图
    }

    for(int i = 1; i <= n; i ++){
        if(color[i]==0){
            dfs(i,1);
        }
    }
    
    if(ans) puts("Yes");
    else puts("No");
    return 0;
}



```

