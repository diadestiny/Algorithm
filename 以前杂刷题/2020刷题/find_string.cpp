#include<iostream>

using namespace std;
string s1, s2;
int ans = 0;
int main(){
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i + s2.length()-1 < s1.length();i++){
        bool matched = true;
        for (int j = 0; j < s2.length();j++){
            if(s1[i+j]!=s2[j]){
                matched = false;
                break;
            }
        }
        if(matched){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}