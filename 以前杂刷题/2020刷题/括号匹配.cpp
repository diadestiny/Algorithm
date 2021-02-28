#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
char s[50005];
stack<char> st;
int ans[50005];
bool f=true;
int main(){
    scanf("%s",s);
    int len = strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='('){
            st.push(i+1);
        }else{
            if(!st.empty()){
                ans[i+1]=st.top();
                st.pop();
            }else{
                f=false;
                break;
            }
        }
    }
    if(!st.empty()){
        f=false;
    }
    if(!f){
        printf("No\n");
    }else{
        printf("Yes\n");
        for(int i=0;i<len;i++){
            if(ans[i+1]){
                printf("%d %d\n",ans[i+1],i+1);
            }
        }
    }

    return 0;
}