```cpp
const int N = 1e9+7;
class Solution {
public:
    long long ans = 0;
    
    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0,j=nums.size()-1;i<j;i++){
            while(i<j && nums[i]+nums[j]>target) j--;
            if(i<j && nums[i]+nums[j]<=target) {
                ans = (ans+j-i)%N;  //j-i表示对于选择左侧数字为nums[i]时,右侧有(j-i)种选择。
            }      
        }
        return (int)ans%N;
    }
};
```



数据范围为1e5,想到如果存在复杂度为O(n)的复杂度可以过。
根据题目很容易想到排序和双指针做法(y总课上讲过这类左右侧的双指针i<j),
重点在于如何一遍扫描就可以累计答案：
1.排序
2.右侧j指针往左走，卡到满足题目条件的时候停止。
2.**难点** 然后想到，对于每次的nums[i]左侧指针固定时，右侧可选数据个数范围为(j-i)，也就是对答案的贡献