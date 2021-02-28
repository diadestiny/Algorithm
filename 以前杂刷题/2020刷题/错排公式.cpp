 #include<iostream>
 using namespace std;

 const int N=1e3+9;
 typedef long long ll;
 ll f[N];
 int main(){
     int n;
     cin>>n;
     f[1]=0;
     f[2]=1;
     for(int i=3;i<=n;i++){
         f[i]=(f[i-1]+f[i-2])*(i-1);
     }
     cout<<f[n]<<endl;
     return 0;
 }