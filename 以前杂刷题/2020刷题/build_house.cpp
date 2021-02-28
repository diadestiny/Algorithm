#include<iostream>

using namespace std;
 int n, m;
void build1(){
     for (int i = 1; i <= 2 * m + 1;i++){
        if(i%2){
            cout << '+';
        }else{
            cout << '-';
        }
    }
    cout << endl;
}
void build2(){
     for (int i = 1; i <= 2 * m + 1;i++){
        if(i%2){
            cout << '|';
        }else{
            cout << '*';
        }
    }
      cout << endl;
}
int main(){
   
    cin >> n >> m;
    for (int i = 1; i <= 2 * n + 1;i++){
        if(i%2){
            build1();
        }else{
            build2();
        }
    }

        return 0;
}