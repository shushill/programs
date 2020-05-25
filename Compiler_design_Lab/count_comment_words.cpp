#include <bits/stdc++.h>
using namespace std;

int main(){
    fstream infile("input.txt", fstream::in | fstream::ate);
    fstream outfile("output.txt", fstream::out | fstream::trunc);
    if(!infile && !outfile){
            cerr<<"Unable to open file"<<endl;
            return EXIT_FAILURE;
    }
    auto end_mark=infile.tellg();
    infile.seekg(0, fstream::beg);
    // variables to count lines of words, no.of characters
    string line, word;
    int numberofcommentwords=0;
    //int numberofLines=0, numberofWords=0, numberofCharcters=0;
    while(infile && (infile.tellg()!=end_mark) && getline(infile, line)){
        istringstream s(line);
        string commentword ="//";
        while(s>>word){
            if(word == commentword)  ++numberofcommentwords;
        }
        auto mark = infile.tellg();
        infile.seekg(mark);
    }
    outfile<<"number of comment words = " <<numberofcommentwords<<endl;



    infile.close();
    outfile.close();
    return 0;
}
