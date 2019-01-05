/* kadai3 */
#include <iostream>
using namespace std;

class person{
public:
    string address;
    string name;
};

class addressbook{
    person* friends;
    int numberOfFriends;
public:
    addressbook(int maximumFriends);
    ~addressbook();
    void listFriends();
    void addFriend(string name);
    void addFriend(string name, string address);
    person find(string query);
};

//constructor
addressbook::addressbook(int maximumFriends){
    numberOfFriends = 0;
    friends = new person [maximumFriends];
}

addressbook::~addressbook()
{
    delete [] friends;
}

void addressbook::addFriend(string n){
    friends[numberOfFriends].name = n;
    numberOfFriends++;
}

void addressbook::addFriend(string n,string a){
    friends[numberOfFriends].name = n;
    friends[numberOfFriends].address = a;
    numberOfFriends++;
}

void addressbook::listFriends(){
    for(int i=0; i < numberOfFriends; i++){
        cout << friends[i].name << "："<< friends[i].address << "\n";
    }
}

person addressbook::find(string q){
    person no_one;
    no_one.name = "";
    for(int i=0; i < numberOfFriends; i++){
        if(friends[i].name == q){
            return friends[i];
        }
    }
    return no_one;
}

int main()
{
    addressbook abook(100);
    string name;
    string address;
    string query;
    person found;
    while(1){
        cout << "住所録に登録する名前を入力してください（終了するにはquitと入力してください）：";
        cin >> name;
        if(name == "quit"){break;}
        cout << "住所録に登録する住所を入力してください";
        cin >> address;
        abook.addFriend(name,address);
    }

    cout << "名前を入力してください：";
    cin >> query;

    found = abook.find(query);

    if(found.name == ""){
        cout << "見つかりませんでした。";
    }else{
        cout << found.name << ":" << found.address << "\n";
    }
    //cout << "\n名前：住所リスト\n";
    //abook.listFriends();

    delete abook(100);
}