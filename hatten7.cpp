/* file_io.cpp */
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main(){

    //ファイル書き出し
    ofstream fout("test.txt");
    if(!fout){cout << "出力ファイルが開けません"; return 1;}
    for(int i = 0; i < 5; i++){
        fout << i << "\n";
    }
    fout.close();

    //ファイル読み込み
    ifstream fin("test.txt");
    if(!fin){cout << "入力ファイルが開けません"; return 1;}
    string str;
    int i;
    while(!fin.eof()){
        //if ( fin.eof() ) break;
        fin >> str;
        if ( fin.eof() ) break;
        cout << "line " << i << ": " << str << "\n";
        i++;
        //if ( fin.eof() ) break;
    }
    fin.close();
    return 0;
}