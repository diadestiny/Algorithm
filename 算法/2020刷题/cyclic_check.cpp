#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int f(int n,int m){
    n = n % m;
    vector<int>v;
    while(1){
        v.push_back(n);
        n *= 10;
        n = n % m;
        if(n==0) return 0;
        if(find(v.begin(),v.end(),n)!=v.end()){
            return v.end() - find(v.begin(), v.end(),n);
        }
    }

}
int main(){
    int n, m;
    cin >> n >> m;
    cout << f(n, m) << endl;

    return 0;
}