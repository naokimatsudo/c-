/* hatten3 */
#include<iostream>
using namespace std;

void exchange(int &x,int &y){
    int a;
    a = y;
    y = x;
    x = a;
    //cout << "x:" << x;
    //cout << "y:" << y;
}

int main(){
    int a = 10;
    int b = 20;
    exchange(a,b);
    cout << "a:" << a << "\n";
    cout << "b:" << b << "\n";
}