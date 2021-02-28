#include<iostream>
using namespace std;
int year, month, day;
int ans = 0;
int main(){
    string weekdays[7] = {"monday", "tuesday", 
    "wednesday", "thursday", "friday", "saturday", "sunday"};
    cin >> year >> month >> day;
    for (int i = 1; i < year;i++){
        if(i%400==0||(i%400!=0&&i%4==0)){
            ans += 366 % 7;
            ans %= 7;
        }else{
            ans += 365 % 7;
            ans %= 7;
        }
    }
    for (int i = 1; i < month;i++){
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
            ans += 31 % 7;
            ans %= 7;
        }else if(i==4||i==6||i==9||i==11){
            ans += 30 % 7;
            ans %= 7;
        }else if(i%400==0||(i%400!=0&&i%4==0)){
            ans += 29 % 7;
            ans %= 7;
        }else{
            ans += 28 % 7;
            ans %= 7;
        }
    }
    ans += (day - 1) % 7;
    ans %= 7;
    cout << weekdays[ans];
    return 0;
}