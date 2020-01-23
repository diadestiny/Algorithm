#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        string space = string(n - i, ' ');
        string ch = string(2*i-1, 'A' + i - 1);
        cout << space + ch << endl;
    }
        return 0;
}