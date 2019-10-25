#include<bits/stdc++.h>
using namespace std;

stack<int> st,st1;
int vis[16];
int num=1;
//Ŀǰ�Ǳ���Ϊ1 �ϰ�Ϊ0
//��ʾũ��״̬�ĺ���������0 ����ʾũ�����ϰ�����֮�ڱ���
int farmer(int location){
    return(0!=(location & 0x08));
}
//��ʾ�ǵ�״̬�ĺ���������0 ����ʾ�����ϰ�����֮�ڱ���
int wolf(int location){
    return(0!=(location & 0x04));
}
//��ʾ�ײ�״̬�ĺ���������0 ����ʾ�ײ����ϰ�����֮�ڱ���
int cabbage(int location){
    return(0!=(location & 0x02));
}
//��ʾ��״̬�ĺ���������0 ����ʾ�����ϰ�����֮�ڱ���
int goat(int location){
    return(0!=(location & 0x01));
}
//�жϵ�ǰ״̬�Ƿ����ĺ���
int safe(int location){
    //���ũ��������ߣ�����Ͱײ���һ����Ϊ����ȫ
    if(goat(location) == cabbage(location) && goat(location) != farmer(location)){
        return 0;
    }
    //���ũ��������ߣ����Ǻ�����һ��Ҳ����ȫ
    if(goat(location) == wolf(location) && goat(location) != farmer(location)){
        return 0;
    }
    //�����������ȫ
    return 1;
}
string explain(int num){
    if(num==0){
        return "��ʼ:�����ϰ�";   
    }
    if(num==15){
        return "����:�����ﱱ��";
    }
    string words[] = {"ũ��","��","�ײ�","��"};
    string str1 = bitset<4>(num).to_string();
    string str2 = "����:";
    string str3 = " \t\t�ϰ�:";
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
        cout << "****************����"<<num<<"****************"<< endl;
        printf("0��ʾ���ϰ���1��ʾ�ڱ���\n");
        printf("0000������ÿλ���ֱ��ʾũ��,��,�ײ�,��\n\n");
        printf("λ��   ������   ����\n");
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
//ũ����ӵ�ʵ�ֺ���
void farmerproblem(){
    st.push(0);
    dfs(0);
}
int main(){
    farmerproblem();
    return 0;
}