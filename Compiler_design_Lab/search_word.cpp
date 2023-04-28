#include <bits/stdc++.h>
using namespace std;

int main(){
    fstream infile("input.txt", fstream::in | fstream::ate);
    if(!infile){
            cerr<<"Unable to open file"<<endl;
            return EXIT_FAILURE;
    }
    auto end_mark=infile.tellg();
    infile.seekg(0, fstream::beg);
    // variables to count lines of words, no.of characters
    string line, word;
    cout<<"Enter a word to be searched "<<endl;
    string searchword; cin>>searchword;
    bool searched = false;
    while(infile && (infile.tellg()!=end_mark) && getline(infile, line)){
        istringstream s(line);
        while(s>>word){
                if(word == searchword){
                    searched = true;
                }
            }
        if(searched){
            break;
        }
        auto mark = infile.tellg();
        infile.seekg(mark);
    }
    cout<<"The searched word is present in a file"<<endl;


    infile.close();
    return 0;
}
