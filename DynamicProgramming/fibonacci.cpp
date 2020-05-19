#include <bits/stdc++.h>
using namespace std;

int table[5];
int fact(int n){
    //base
    if(n == 0 or n == 1) return 1;

    //cache
    if(table[n]) return table[n];

    table[n] = fact(n-1) + fact(n-2);
    return table[n];
}
void bottomup(){
    for(int i = 2; i <5; ++i){
        table[i] = table[i-1] + table[i -2];
    }
}
int main(){
    for(int i =0; i < 5; ++i){
        table[i] = 0;
    }
    table[0] = table[1] = 1;
    bottomup();
    for(int i = 0; i <5; ++i){
        cout << table[i] << " ";
    }
}
