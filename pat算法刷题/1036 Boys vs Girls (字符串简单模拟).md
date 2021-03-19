```cpp
#include<bits/stdc++.h>

using namespace std;
int n;
pair<string,string> female,male;
int m_g = INT_MAX,f_g = -1;
int f1,f2;
int main(){
    cin>>n;
    string name,sex,id;
    int grade;
    while(n--){
        cin>>name>>sex>>id>>grade;
        if(sex == "F") {
           if(f1==1||grade>f_g) {
                f_g = grade;
                f1 = 0;
                female = make_pair(name,id);
           }
        }else{
            if(f2==1||grade<m_g) {
                m_g = grade;
                f2 = 0;
                male = make_pair(name,id);
           }
        }
    }
    int flag = 1;
    if(female.first=="") cout<<"Absent"<<endl,flag = 0;
    else cout<<female.first<<" "<<female.second<<endl;
    if(male.first=="") cout<<"Absent"<<endl,flag = 0;
    else cout<<male.first<<" "<<male.second<<endl;
    if(!flag) cout<<"NA";
    else cout<<f_g-m_g;
    return 0;
}
```

