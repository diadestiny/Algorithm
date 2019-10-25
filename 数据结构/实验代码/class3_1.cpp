#include<bits/stdc++.h>
#include "orderqueue.h"

using namespace std;
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
//农夫过河的实现函数
void farmerproblem(){
    int movers,location,newlocation;
    int route[16];//用于记录已考虑的状态路径
    int i;
    SqQueue moveto;
    Init_SqQueue(&moveto);
    //以所有角色都在南岸开始
    In_SqQueue(&moveto,0x00);
    //对记录路径的数组初始化
    for(i=0;i<16;i++){
        route[i] = -1;
    }
    route[0] = 0;
    while(!Empty_SqQueue(&moveto) && (route[15] == -1)){
        Out_SqQueue(&moveto,&location);//出队列，并将状态赋值给location
        //依次移动羊、白菜、狼和农夫，movers每次左移一位，所以其值每次为1,2,4,8
        for(movers =1;movers<=8;movers<<=1){
            //判断农夫与要移动的角色是否位于河岸的同一侧
            if(((location & 0x08)!=0) == ((location & movers)!=0)){
                //若农夫与该角色在同一侧则尝试移至对岸（异或运算）
                newlocation = location^(0x08|movers);
                //判断此移动是否安全
                if(safe(newlocation) && route[newlocation] == -1){
                    //如果安全，且之前没有移动过，则进行记录，记录方法是在新位置记录之前的移动位置
                    route[newlocation] = location;
                    //将新的移动方案入队
                    In_SqQueue(&moveto , newlocation);
                }
            }
        }
    }
    //如果最终移动成功，即由 0000 变成 1111则视为成功
    int reverse[15];
    int j = 0;
    if(route[15]!=-1){
        printf("0表示在南岸，1表示在北岸\n");
        printf("0000二进制每位数分别表示农夫,浪,白菜,羊\n\n");
        printf("位置   二进制   解释\n");
        for(int i=15; i>=0; i=route[i]){
            reverse[j] = i;
            j++;
            if(i==0){
                break;
            }
        }
        for (int k = j - 1; k >= 0; k--){
            cout << reverse[k] << "\t" << bitset<4>(reverse[k]) << "   ";
            cout << explain(reverse[k]) << endl;
            }
        }
    else{
        cout << "no path" << endl;
    }
}
int main(){
    farmerproblem();
    return 0;
}