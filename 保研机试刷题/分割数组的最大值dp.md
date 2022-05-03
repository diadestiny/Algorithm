```cpp
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        long long dp [1005][55],sum[1005];
        memset(dp,0x3f,sizeof dp);
        for(int i=1;i<=n;i++) sum[i] = sum[i-1]+nums[i-1];
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=min(i,m);j++){
                if(j == 1) dp[i][j] = sum[i];
                else {
                   for(int k=1;k<=i-1;k++){
                    dp[i][j] = min(dp[i][j],max(dp[k][j-1],sum[i]-sum[k]));
                 }
                }
               
            }
        }


        return dp[n][m];
    }
};
```

