/* kadai6.cpp */
#include <iostream>
#include <stdio.h>
using namespace std;

class person{
protected:
    string name;
public:
    void setName(string n){name = n;}
    string getName(){return name;}
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
};

//このtrainTicketクラスがhmクラスのインスタンスへのポインタであるdepartureTimeとarrivalTimeをメンバとして持っている
class trainTicket : public transTicket {
public:
    hm* departureTime;
    hm* arrivalTime;
    //このコンストラクタでhmクラスへのインスタンスも生成しなければいけない
    //newをしておかないとコンパイルは成功してもメモリのアクセスの関係で実行時にsegmentation falseエラーが出てしまう
    //この行をいれたことにより解決できた。
    trainTicket(): transTicket(){departureTime = new hm, arrivalTime = new hm;};
};

int main(){
    int ticketNum;
    int d_hour;
    int d_minute;
    int a_hour;
    int a_minute;
    string name;
    cout << "チケットを何枚を購入しますか？";
    cin >> ticketNum;
    cout << "\n";
    trainTicket* tickets = new trainTicket [ticketNum];
    for(int i = 0; i < ticketNum; i++){
        tickets[i].id = i+1;
        cout << i+1 << "人目の利用者の名前を入力してください：";
        cin >> name;
        tickets[i].user->setName(name);
        cout << "出発地を入力してください：";
        cin >> tickets[i].origin;
        cout << "到着地を入力してください：";
        cin >> tickets[i].destination;
        cout << "出発時刻を入力してください ex)8:15：";
        scanf("%d:%d", &d_hour, &d_minute);
        tickets[i].departureTime->hour = d_hour;
        tickets[i].departureTime->minute = d_minute;
        //cout << "出発時刻を入力してください ex)8：";
        //cin >> tickets[i].departureTime->hour;
        //cout << "出発時刻を入力してください ex)17：";
        //cin >> tickets[i].departureTime->minute;
        cout << "到着時刻を入力してください ex)8:15：";
        scanf("%d:%d", &a_hour, &a_minute);
        tickets[i].arrivalTime->hour = a_hour;
        tickets[i].arrivalTime->minute = a_minute;

    }
    cout << "\nチケット利用者一覧：\n";
    for(int i = 0; i < ticketNum; i++){
        trainTicket t = tickets[i];
        cout << " " << t.id << "：" << t.user->getName() << "："<<t.origin<<"=>"<<t.destination << "\n" ;
        cout <<"出発時刻は"<<t.departureTime->hour<<":"<<t.departureTime->minute<<"\n";
        cout <<"到着時刻は"<<t.arrivalTime->hour<<":"<<t.arrivalTime->minute<<"\n";

    }
    cout << "\n";
}

