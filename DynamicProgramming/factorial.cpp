#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int f[N];
void bottomup(){
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <N; ++i){
        f[i] = f[i-1] * i;
    }
    for(int i = 0; i < N; ++i){
        cout << f[i] <<" ";
    }
    cout << "\n";
}
int fact(int n){
    //base
    if(n == 1) {
        cout <<  f[1]<<" ";
        return 1;
    }
    f[n] = fact(n-1) * n;
    cout << f[n] << " ";
    return f[n];
}
int main(){
    //;
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    f[1] = 1;
    bottomup();
    fact(9);
    cout <<endl;
    return 0;
}
