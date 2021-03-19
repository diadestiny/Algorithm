```cpp
#include<bits/stdc++.h>

using namespace std;
int n,c;
struct student{
    string id,name;
    int grade;
    student(string i,string n,int g){
        id = i,name=n,grade = g;
    }
    student(){}
};

bool cmp1(student s1,student s2){
    return s1.id<s2.id;
}
bool cmp2(student s1,student s2){
    if(s1.name ==s2.name){
        return s1.id<s2.id;
    }else{
        return s1.name <=s2.name;
    }
}
bool cmp3(student s1,student s2){
    if(s1.grade ==s2.grade){
        return s1.id<s2.id;
    }else{
        return s1.grade <=s2.grade;
    }
}
student v[100005];
int main(){
    cin>>n>>c;
    string tid,tname;
    int tg;
    int i = 0;
    for(int i=0;i<n;i++){
        cin>>tid>>tname>>tg;
        v[i] = student(tid,tname,tg);
    }    
    if(c==1){
        sort(v,v+n,cmp1);
    }
    else if(c==2){
        sort(v,v+n,cmp2);
    }
    else{
        sort(v,v+n,cmp3);
    }
    for(int i=0;i<n;i++){
        printf("%s %s %d\n", v[i].id.c_str(), v[i].name.c_str(), v[i].grade);
    }
    return 0;
}
```

