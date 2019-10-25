#include<bits/stdc++.h>
#include "orderqueue.h"

using namespace std;
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
//ũ����ӵ�ʵ�ֺ���
void farmerproblem(){
    int movers,location,newlocation;
    int route[16];//���ڼ�¼�ѿ��ǵ�״̬·��
    int i;
    SqQueue moveto;
    Init_SqQueue(&moveto);
    //�����н�ɫ�����ϰ���ʼ
    In_SqQueue(&moveto,0x00);
    //�Լ�¼·���������ʼ��
    for(i=0;i<16;i++){
        route[i] = -1;
    }
    route[0] = 0;
    while(!Empty_SqQueue(&moveto) && (route[15] == -1)){
        Out_SqQueue(&moveto,&location);//�����У�����״̬��ֵ��location
        //�����ƶ��򡢰ײˡ��Ǻ�ũ��moversÿ������һλ��������ֵÿ��Ϊ1,2,4,8
        for(movers =1;movers<=8;movers<<=1){
            //�ж�ũ����Ҫ�ƶ��Ľ�ɫ�Ƿ�λ�ںӰ���ͬһ��
            if(((location & 0x08)!=0) == ((location & movers)!=0)){
                //��ũ����ý�ɫ��ͬһ�����������԰���������㣩
                newlocation = location^(0x08|movers);
                //�жϴ��ƶ��Ƿ�ȫ
                if(safe(newlocation) && route[newlocation] == -1){
                    //�����ȫ����֮ǰû���ƶ���������м�¼����¼����������λ�ü�¼֮ǰ���ƶ�λ��
                    route[newlocation] = location;
                    //���µ��ƶ��������
                    In_SqQueue(&moveto , newlocation);
                }
            }
        }
    }
    //��������ƶ��ɹ������� 0000 ��� 1111����Ϊ�ɹ�
    int reverse[15];
    int j = 0;
    if(route[15]!=-1){
        printf("0��ʾ���ϰ���1��ʾ�ڱ���\n");
        printf("0000������ÿλ���ֱ��ʾũ��,��,�ײ�,��\n\n");
        printf("λ��   ������   ����\n");
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