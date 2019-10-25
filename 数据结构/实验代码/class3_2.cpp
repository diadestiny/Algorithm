#include<bits/stdc++.h>
using namespace std;

stack<int> st,st1;
int vis[16];
int num=1;
//目前是北岸为1 南岸为0
//表示农夫状态的函数，返回0 ，表示农夫在南岸，反之在北岸
int farmer(int location){
    return(0!=(location & 0x08));
}
//表示狼的状态的函数，返回0 ，表示狼在南岸，反之在北岸
int wolf(int location){
    return(0!=(location & 0x04));
}
//表示白菜状态的函数，返回0 ，表示白菜在南岸，反之在北岸
int cabbage(int location){
    return(0!=(location & 0x02));
}
//表示羊状态的函数，返回0 ，表示羊在南岸，反之在北岸
int goat(int location){
    return(0!=(location & 0x01));
}
//判断当前状态是否合理的函数
int safe(int location){
    //如果农夫不在羊身边，而羊和白菜在一起，则为不安全
    if(goat(location) == cabbage(location) && goat(location) != farmer(location)){
        return 0;
    }
    //如果农夫不在狼身边，而狼和羊在一起，也不安全
    if(goat(location) == wolf(location) && goat(location) != farmer(location)){
        return 0;
    }
    //其他情况都安全
    return 1;
}
string explain(int num){
    if(num==0){
        return "开始:都在南岸";   
    }
    if(num==15){
        return "结束:都到达北岸";
    }
    string words[] = {"农夫","狼","白菜","羊"};
    string str1 = bitset<4>(num).to_string();
    string str2 = "北岸:";
    string str3 = " \t\t南岸:";
    for (int i = 0; i < 4;i++){
        if(str1[i]=='1'){
            str2 += words[i]+" ";
        }
        else{
            str3 += words[i]+" ";
        }
    }
        return str2+str3;
}
void dfs(int location){
    if(location==15){
        cout << "****************方案"<<num<<"****************"<< endl;
        printf("0表示在南岸，1表示在北岸\n");
        printf("0000二进制每位数分别表示农夫,浪,白菜,羊\n\n");
        printf("位置   二进制   解释\n");
        num++;
        while(!st.empty()){
            int temp = st.top();
            st.pop();
            st1.push(temp);
        }
        while(!st1.empty()){
            int temp = st1.top();
            st1.pop();
            st.push(temp);
            cout << temp<<"\t"<<bitset<4>(temp) << "   ";
            cout << explain(temp) << endl;
        }
        return ;
    }
        for(int movers =8;movers>=1;movers>>=1){
               if (((location & 0x08) != 0) == ((location & movers) != 0))
               {
                   int newlocation = location ^ (0x08 | movers);
                   if (safe(newlocation) && vis[newlocation] == 0)
                   {
                       vis[newlocation] = 1;
                       st.push(newlocation);
                       dfs(newlocation);
                       vis[newlocation] = 0;
                       st.pop();
                   }
             }
     }

}
//农夫过河的实现函数
void farmerproblem(){
    st.push(0);
    dfs(0);
}
int main(){
    farmerproblem();
    return 0;
}