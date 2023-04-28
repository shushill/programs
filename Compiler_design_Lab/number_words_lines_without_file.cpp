#include <bits/stdc++.h>
using namespace std;

int main(){

    string line, word;
    int numberofLines=0, numberofWords=0, numberofCharcters=0;
    cout<<"enter lines of text"<<endl;
    while(cin && getline(cin, line) && line.size()!= 0){
        if(line.size()!=0) numberofLines++;
        istringstream s(line);
        while(s>>word){
            numberofWords++;
            numberofCharcters += word.size();
        }
    }

    cout<<"Lines = "<<numberofLines<<endl;
    cout<<"words = "<<numberofWords<<endl;
    cout<<"charcters = "<<numberofCharcters<<endl;
    return 0;
}
