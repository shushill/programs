#include <bits/stdc++.h>
using namespace std;

int main(){

    string line, word;
    map<string, size_t> wordrepeat;
    int numberofLines=0, numberofWords=0, numberofCharcters=0;
    cout<<"enter lines of text"<<endl;
    while(cin && getline(cin, line) && line.size()!= 0){
        istringstream s(line);
        while(s>>word){
            ++wordrepeat[word];
        }
    }
    for(auto it = wordrepeat.begin(); it != wordrepeat.end(); ++it){
        cout<<it->first<< " --> "<<it->second<<endl;
    }
    return 0;
}
