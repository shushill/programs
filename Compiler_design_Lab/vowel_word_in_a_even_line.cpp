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
    int numberofLines=0;// numberofWords=0, numberofCharcters=0, numberofvowelinoddplaces=0;
    //int numberofvowelinevenplaces =0;
    int numberofwordswitha=0;
    while(infile && (infile.tellg()!=end_mark) && getline(infile, line)){
        numberofLines++;
        istringstream s(line);
        while(s>>word){
            if((word[0] == 'a' ) && ((numberofLines % 2 )==0)){
                numberofwordswitha++;
            }
        }
        auto mark = infile.tellg();
        infile.seekg(mark);
    }


    outfile<<"Vowels word starting with a = "<<numberofwordswitha<<endl;



    infile.close();
    outfile.close();
    return 0;
}
