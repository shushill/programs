#include<bits/stdc++.h>
using namespace std;

bool validstirng(string s, int sz){
    if(!((s[0]== '_') || (isalpha(s[0])))) return false;
    for(int i =1; i<sz; ++i){
        if(!((s[i] == '_') || (isalnum(s[i])))){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    int sz = s.size();
    if(validstirng(s, sz)){
        cout<<"Valid string"<<endl;
    }else{
        cout<<"Invalid String"<<endl;
    }
}
