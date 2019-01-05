/* hatten5.cpp */
#include <iostream>
using namespace std;
class movie{
public:
    string title;
    movie(string t){title = t;};
};
class copyprotection{
public:
    string code;
    copyprotection(string c){code = c;};
};
class protectedMovie : public movie, public copyprotection{
public:
    protectedMovie(string t, string c) : movie(t), copyprotection(c){};
};
int main(){
 protectedMovie pm("カメラを止めるな", "kametome");
 cout << "映画のタイトルは　" << pm.title << " プロテクトコードは　"<< pm.code << " です。\n" ;
};