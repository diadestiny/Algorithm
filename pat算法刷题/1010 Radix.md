* 19分做法(有坑,进制可以很大)

```cpp

#include<bits/stdc++.h>
using namespace std;

string a,b,tag,radix;
long long tod(string s,int ra){
    long long sum = 0;
    long long j = 0;
    
    for(int i=s.length()-1;i>=0;i--){
        long long t;
        if(s[i]>='0' && s[i] <='9'){
            t =s[i]-'0';
            
        }else{
            t = s[i]-'a'+10;
        }
            long long tc = 1;
            long long tj = j;
            while(tj--){
                tc*=ra;
            }
            sum += tc*t;
        j++;
    }
    return sum;
}
int main(){
    
    cin>>a>>b>>tag>>radix;
    long long q;
    int flag = 0;
    char ma = 'a';
    char ma2 = '0';
    if(tag=="1"){
        q = tod(a,stoi(radix));
       // cout<<q;
        for(int i=0;i<b.size();i++){
            if(b[i]>='a' && b[i] <='z'){
                flag = 1;
                if(b[i]>ma) ma = b[i];
            }
        }
        
        for(int i=0;i<b.size();i++){
            if(b[i]>='0' && b[i] <='9'){
                flag = 2;
                if(b[i]>ma2) ma2 = b[i];
            }
        }
        if(flag == 1){
            
            for(int i=ma-'a'+11;i<=36;i++){
            if(tod(b,i)==q){
                cout<<i;
                return 0;
            }
            }
        }
        else if(flag == 2){
            for(int i=ma2-'0'+1;i<=36;i++){
                if(tod(b,i)==q){
                    cout<<i;
                    return 0;
                }
            }
        }
        
        
    }
    else{
        q = tod(b,stoi(radix));
        
         for(int i=0;i<a.size();i++){
            if(a[i]>='a' && a[i] <='z'){
                flag = 1;
                if(a[i]>ma) ma = a[i];
            }
        }
        
        for(int i=0;i<b.size();i++){
            if(a[i]>='0' && a[i] <='9'){
                flag = 2;
                if(a[i]>ma2) ma2 = a[i];
            }
        }
        if(flag == 1){
            
            for(int i=ma-'a'+11;i<=36;i++){
            if(tod(a,i)==q){
                cout<<i;
                return 0;
            }
            }
        }
        else if(flag == 2){
           // cout<<ma2-'0'+1;
            for(int i=ma2-'0'+1;i<=36;i++){
                
                if(tod(a,i)==q){
                    cout<<i;
                    return 0;
                }
            }
        }
        
    }
    cout<<"Impossible";
    
    
    return 0;
}
```



* 秦九韶算法(任意进制字符串转十进制数)+二分查找

  ```cpp
  #include<iostream>
  #include<algorithm>
  
  using namespace std;
  
  typedef long long LL ;
  
  int get(char c)
  {
      if (c <= '9') return c - '0';  // 刚开始写成了 9，应该写'9'
      else return c - 'a' + 10;
  }
  
  LL cal(string n, LL r)
  {
      LL res = 0;
      for (auto c : n)
      {
          if ((double)res * r + get(c) > 1e16) return 1e18;
          res = res * r + get(c);
      }
      return res;
  }
  
  int main()
  {
      string s1, s2;
      int tag, radix;
  
      cin >> s1 >> s2 >> tag >> radix;
      if (tag == 2) swap(s1, s2);
  
      // 转成十进制的target
      LL target = cal(s1, radix);
  
  
  
      LL l = 0, r = target + 1;  //  + 1
      for (auto c : s2) l = max(l, (LL)get(c) + 1);
  
      while(l < r)
      {
          LL mid = l + r >> 1;
          if (cal(s2, mid) >= target) r = mid;
          else l = mid + 1;
      }
  
      if (cal(s2, r) != target) puts("Impossible");
      else cout << r << endl;
      return 0;
  }
  
  ```

  