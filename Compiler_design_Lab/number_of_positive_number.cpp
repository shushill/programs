#include<bits/stdc++.h>
using namespace std;
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cin.tie(NULL);

    int num, count =0;
    cout<<"Enter number and press Y if all the number is entered"<<endl;
    while(cin>>num){
        if(num>0){
            count++;
        }
    }



    cout<<count<<endl;
    return 0;
}
