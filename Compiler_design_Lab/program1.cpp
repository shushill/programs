#include <bits/stdc++.h>
using namespace std;

int main(){
    fstream file("myfile.txt", fstream::in | fstream::ate);
    fstream output("results.txt", fstream::out | fstream::trunc);

    if(!file and !output){
        cerr<<"Unable to open files"<<endl;
        return EXIT_FAILURE;
    }
    auto end_mark = file.tellg();
    file.seekg(0, fstream::beg);
    size_t cnt = 0;
    string line;
    size_t cntwords = 0;
    size_t cntspace = 0 ;
    size_t cntliterals =0;
    map<string, size_t> word_repeat;
    while(file and file.tellg() not_eq end_mark and getline(file, line)){
        cnt = line.size();
        istringstream cwords(line);
        string word;
        while(cwords>>word){
            cntwords += 1;
            ++word_repeat[word];
        }
        int i=0;
        while(i<cnt){
            if(line[i++] == ' ' ) cntspace += 1;
        }
        string pattern = "//";
        regex r(pattern);
        //smatch result;
        for(sregex_iterator it(line.begin(), line.end(), r), end; it != end; ++it){
            cntliterals +=1;
        }
        auto mark = file.tellg();
        file.seekp(0, fstream::end);
        output << cnt ;
        if(mark not_eq end_mark) output << " ";
        file.seekg(mark);
    }
    output <<"\nwords= " << cntwords<< "\nspaces= "<<cntspace<<"\nliterals= "<<cntliterals<<"\n";
    for(const auto &w : word_repeat){
        output << w.first<<" "<<w.second<<"\n";
    }
    output.close();
    file.close();
    return 0;
}
