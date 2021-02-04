bfs:

```cpp
#include<bits/stdc++.h>

using namespace std;

int n,m;
map<string,vector<string> >p;
int f[105];//标记是否有叶子节点
queue<string> q;//bfs队列
int main(){
    cin>>n>>m;
    int i=0;
    while(m--){
        string ts;
        cin>>ts;
        int k,t_k;
        cin>>k;
        t_k = k;
        vector<string> vs;
        while(k--){
            string c_ts;
            cin>>c_ts;
            vs.push_back(c_ts);
        }
        p[ts] = vs;
        if(t_k) f[stoi(ts)] = 1;
    }
    string start = "01";
    if(f[stoi(start)]==0){
        cout<<1;
        return 0;
    }
    cout<<"0";
    q.push(start);
    int tc = 1; //记录当前这一层需要遍历多少个结点,不然分不清层数
    int nc = 0; //记录下一层需要遍历多少个结点数
    int t_count = 0; //每一层的叶子数
    while(!q.empty()){
        string tp =q.front();
        q.pop();
        for(int i=0;i<p[tp].size();i++){
            if(f[stoi(p[tp][i])] == 0){
                t_count ++;
            }
            else{
                q.push(p[tp][i]);
                nc++;
            }
        }
        tc--;
        if(tc == 0){
            cout<<" "<<t_count;
            t_count = 0;
            tc = nc;
            nc = 0;
        }
    }
    return 0;
}

```

