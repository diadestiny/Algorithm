* string

  >  str .length() str.size()

* atoi() or stoi() 、to_string()

* 注意题目数据范围

```cpp
#include<bits/stdc++.h>

using namespace std;

string table[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};


int main(){
    string a;
    cin>>a;
    long long sum = 0;
    for(auto i=0;i<a.length();i++){
        sum+=a[i]-'0';
    }
    string ts = to_string(sum);
    for(int i=0;i<ts.size();i++){
        cout<<table[ts[i]-'0'];
        if(i!=ts.size()-1){
            cout<<" ";
        }
    }
    return 0;
}

```

