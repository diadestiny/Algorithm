```cpp
#include<bits/stdc++.h>

using namespace std;

int k;
int num[100005],dp[100005];
//dp[i]为i向前最大和
int res = -0x3f;

int l,r;
int t1;

int main(){
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>num[i];
    }

    int flag = 0;
    for(int i=0;i<k;i++){
        if(num[i]>=0) {flag = 1;break;}
    }
    if(!flag){
        cout<<"0 "<<num[0]<<" "<<num[k-1];
        return 0;
    }
    t1 = r = 0;
    for(int i=0;i<k;i++){
        if(i == 0) dp[i] = max(0,num[i]);
        dp[i] = max(dp[i-1]+num[i],num[i]);
        if(dp[i-1]+num[i]<num[i])  t1 = i;
        
        if(res < dp[i]){
            res = dp[i];
            r = i;
            l = t1;
        }
        
    }
   cout<<res<<" "<<num[l]<<" "<<num[r];
    return 0;
}

```

