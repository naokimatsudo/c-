/* hatten2.cpp */
#include <iostream>
#include <stdio.h>
using namespace std;

class person{
public:
    string name;
};

class ticket{
public:
    int id;
    person* user;
    ticket(){user = new person;}
};

class transTicket : public ticket {
public:
    string origin;
    string destination;
    transTicket(): ticket(){};
};

class hm {
public:
    int hour;
    int minute;
    int inMinutes();
    hm(int timeInMinutes){hour = timeInMinutes/60, minute = timeInMinutes%60;}
};

int hm::inMinutes(){
    return hour * 60 + minute;
}

int main(){
   int n;
   int a;
   cout << "時間を入力して下さい。：";
   cin >> n;
   hm t(n);
   cout << t.hour << "時間" << t.minute << "分です。"<<"\n";
    a=t.inMinutes();
    cout << a << "\n";
}

