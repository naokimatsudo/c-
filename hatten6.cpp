/* file_io.cpp */
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main(){
    string f_name;
    cout << "バックアップしたいファイル名を入力して下さい。\n";
    cin >> f_name;
    ifstream fin(f_name);
    f_name.append(".backup");
    ofstream fout(f_name);
    if(!fout){cout << "出力ファイルが開けません"; return 1;}
    if(!fin){cout << "入力ファイルが開けません"; return 1;}
    string str;
    while(!fin.eof()){
        fin >> str;
        fout << str << "\n";
    }
    fout.close();
    fin.close();
    return 0;
}