## sort自定义排序
```cpp
bool cmp(int a,int b){
    return a<b;
}
sort(nums.begin(),nums.end(),cmp);
sort(nums.begin(),nums.end(),greater<int>());//从大到小
```
## stack<> queue<>  
push() pop() top() empty()

## vector
* vector<int> vec(n,0) //n个0 
* vec.push_back()
* vec.pop_back()
* vec.size()
* vec.clear()

## set
* set<string> s;
* s.insert("fool");//O(logn)
* s.erase("fool"); //O(logn)
* s.count("fool") 返回值1/0代表集合里面有没有 //O(logn)
* s.size();//O(1)
* s.clear();//O(n)
* set<string>::iterator it=s.begin();it!=s.end()[尾后迭代器];it++;cout<<*it<<endl;
* set排序默认从小到大
* 重载operator<

```cpp
struct Node{
	int x,y;
	bool operator<(const Node& rhs) const{
		if(x==rhs.x){
			return y< rhs.y;
		}
		else{
			return x<rhs.x;
		}

	}
	
};
```
## map
