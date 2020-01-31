#include<set>
#include<iostream>
using namespace std;
struct Point{
    int x,y;
    bool operator<(const Point& a) const{
        if(x==a.x){
            return y<a.y;
        }else{
            return x<a.x;
        }
    }
};
int main(){
    int n;
    set<Point> s;
    cin>>n;
    for(int i=0;i<n;i++){
        Point temp;
        cin>>temp.x>>temp.y;
        s.insert(temp); 
    }
    //set排序默认从小到大
    for(set<Point>::iterator it=s.begin();it!=s.end();it++){
        cout<<it->x<<" "<<it->y<<endl;
    }

    return 0;
}