#include<iostream>

using namespace std;

int main(){
    char n;
    cin >> n;
    if(n>='A'&&n<='Z'){
        for (int i = 1; i <= n - 'A' + 1;i++){
            for (int j = 1; j <= n - 'A' + 1 - i;j++){
                cout << " ";
            }
            for (int j = 1; j <= i;j++){
                cout << char('A' + j-1);
            }
            for (int j = 1; j <= i-1 ;j++){
                cout << char('A'+i- j-1);
            }
                cout << endl;
        }
    }
    else{
        for (int i = 1; i <= n - '1' + 1;i++){
            for (int j = 1; j <= n - '1' + 1 - i;j++){
                cout << " ";
            }
            for (int j = 1; j <= i;j++){
                cout << char('1' + j-1);
            }
            for (int j = 1; j <= i-1 ;j++){
                cout << char('1'+i- j-1);
            }
                cout << endl;
        }
    }
   
        return 0;
}