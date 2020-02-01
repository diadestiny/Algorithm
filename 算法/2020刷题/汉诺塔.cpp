#include<iostream>
#include<stack>
using namespace std;
stack<int> s[3];
void move(int a,int b){
    int temp =s[a].top();
    s[a].pop();
    s[b].push(temp);
    cout<<a<<"-->"<<b<<endl;
}
void handnoi(int a,int b,int c,int n){
    if(n==1) {
        move(a,c);
        return;
    }
    handnoi(a,c,b,n-1);
    move(a,c);
    handnoi(b,a,c,n-1);
}
int main(){
    int n;
    cin>>n;
    for(int i=n;i>=1;i--){
        s[0].push(i);
    }
    handnoi(0,1,2,n);
    while(!s[2].empty()){
        cout<<s[2].top()<<" ";
        s[2].pop();
    }
    return 0;
}