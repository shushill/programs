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
    map<string, size_t>wordrepeat;
    // int numberofLines=0, numberofWords=0, numberofCharcters=0;
    while(infile && (infile.tellg()!=end_mark) && getline(infile, line)){
        //if(line.size()!=0) numberofLines++; //non empty numberofLines
        istringstream s(line);
        while(s>>word){
            ++wordrepeat[word];
        }
        auto mark = infile.tellg();
        infile.seekg(mark);
    }
    for(auto it = wordrepeat.begin(); it != wordrepeat.end(); ++it){
        outfile<<it->first<< " --> "<<it->second<<endl;
    }


    infile.close();
    outfile.close();
    return 0;
}
