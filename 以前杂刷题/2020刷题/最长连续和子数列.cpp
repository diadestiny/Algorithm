#include<iostream>
#include<algorithm>
using namespace std;
int ans=-10000;
int a[1005],dp[1005];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //暴力 O(n^3)
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         int temp=0;
    //         for(int k=i;k<=j;k++){
    //            temp+=a[k];
    //         }
    //         if(temp>ans){
    //            ans=temp;
    //         }
    //     }
    // }

    //一直往后 动态规划算法O(n)
    ans=0;
    int sum=0;  
    for(int i=0;i<n;i++){
        if(sum+a[i]<0){
            sum=0;
            continue;
        }else if(sum+a[i]>0&&a[i]<0){
            sum+=a[i];
        }else{
            sum+=a[i];
            ans=sum;
        }
    }
    cout<<ans;
    return 0;
}
// -2 11 -4 13 -5 -2