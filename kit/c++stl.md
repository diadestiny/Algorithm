## sort自定义排序
```cpp
bool cmp(int a,int b){
    return a<b;
}
sort(nums.begin(),nums.end(),cmp);
sort(nums.begin(),nums.end(),greater<int>());//从大到小
```
## stack<> queue<>  
push() pop() top() empty() size()

## vector
* vector<int> vec(n,0) //n个0 
* vec.push_back()
* vec.pop_back()
* vec.size()
* vec.clear()
* vector<int>().swap(vtemp) //clear不清除空间
```cpp
vector<int> v[10005];
v[x].push_back(y);
```

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
* 学会set<people> 挺有用的 自定义重载比较大小
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
* map<string,int> dict;
* dict.insert(make_pair("dia",666));
* dict.count("dia");
* dict.size();
* dict.clear();
* 迭代器从小到大访问;
* map<string,int>::iterator it;it->first,it->second;

> map<int,set<string>> class;
> map<string,int> 可以保存一类书对应的本数

### **string str cin cout数据10^6超时
1. 用char str[10] scanf("%s",str);;
2. 改用scanf("%s",str.c_str()); printf("%s",(it->first).c_str());