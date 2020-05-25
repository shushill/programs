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
    int numberofLines=0, numberofWords=0, numberofCharcters=0, numberofvowelinoddplaces=0;
    int numberofvowelinevenplaces;
    set<char> vowelLetter = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    while(infile && (infile.tellg()!=end_mark) && getline(infile, line)){
        istringstream s(line);
        while(s>>word){
            numberofWords++;
            if(numberofWords % 2){  //vowels word in odd places
                if(vowelLetter.find(word[0]) != vowelLetter.end()){
                    ++numberofvowelinoddplaces;
                }
            }else{              // vowels word in even places
                if(vowelLetter.find(word[0]) != vowelLetter.end()){
                    ++numberofvowelinevenplaces;
                }
            }
        }
        auto mark = infile.tellg();
        infile.seekg(mark);
    }


    outfile<<"Vowels word in odd places = "<<numberofvowelinoddplaces<<endl;
    outfile<<"Vowels word in even places = "<<numberofvowelinevenplaces<<endl;


    infile.close();
    outfile.close();
    return 0;
}
