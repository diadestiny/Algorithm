## sort自定义排序
```cpp
bool cmp(int a,int b){
    return a<b;
}
sort(nums.begin(),nums.end(),cmp);
sort(nums.begin(),nums.end(),greater<int>());//从大到小
```
## stack<> queue<>  
> push() pop() top() empty()