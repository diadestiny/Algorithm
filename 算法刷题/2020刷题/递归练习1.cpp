#include<iostream>
using namespace std;
long long fab(int x){
    if(x<=0) return 0;
    else if(x==1) return 1;
    else if(x>1 && x%2==0){
        return 3*fab(x/2)-1;
    }else if(x>1 && x%2==1){
        return 3*fab((x+1)/2)-1;
    }
}
int main(){
    int x;
    cin>>x;
    cout<<fab(x);
    return 0;
}