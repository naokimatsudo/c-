/* kadai5 */
#include <iostream>
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

class trainTicket : public transTicket {
public:
    trainTicket(): transTicket(){};
};

int main(){
    
}