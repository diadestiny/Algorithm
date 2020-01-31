#include<iostream>
using namespace std;
int A[51][51];
int main(){
    int n,m,ans;
    cin>>n>>m;
    ans=-1005;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    for(int up=0;up<n;up++){
        for(int down=up;down<n;down++){
            for(int left=0;left<m;left++){
                for(int right=left;right<m;right++){
                    int tmp=0;
                    for(int i=up;i<=down;i++){
                        for(int j=left;j<=right;j++){
                            tmp+=A[i][j];
                        }
                       
                    }if(tmp>ans){
                        ans=tmp;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;


    return 0;
}