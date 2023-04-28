#include<bits/stdc++.h>
using namespace std;

bool validkeyword(string s){
    set<string> keywordset{
"auto",        "double",      "int",        "struct",
"break",        "else",       "long",       "switch",
"case",         "enum",        "register",   "typedef",
"char",         "extern",      "return",     "union",
"const",        "float",       "short",      "unsigned",
"continue",     "for",         "signed",     "void",
"default",      "goto",        "sizeof",     "volatile",
"do",           "if",          "static",     "while"
};
    if(keywordset.find(s) != keywordset.end()){
        return true;
    }
    return false;
}

int main(){
    string s;
    cin>>s;
    if(validkeyword(s)){
        cout<<"Valid keyword"<<endl;
    }else{
        cout<<" Not a Keyword "<<endl;
    }
}
