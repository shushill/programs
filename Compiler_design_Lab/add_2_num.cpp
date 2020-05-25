#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, carry;
    cout <<"enter two numbers "<<endl;
    cin>>a>>b;
    while(b !=0){
        carry = a&b;
        a = a^b;
        b = carry<<1;
    }
    cout<<"sum = "<<a<<endl;
}
