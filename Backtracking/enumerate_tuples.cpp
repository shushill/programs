#include "C++template.h"

int solution[5];

void print_solution(){
    for(int i =0; i<5; ++i){
        cout << solution[i] << " ";
    }
    cout << endl;
}

void backtrack(int n){
    if(n == 5){
        print_solution();
        return;
    }

    solution[n] = 1;
    backtrack(n+1);

    solution[n] = 2;
    backtrack(n+1);

    solution[n] = 3;
    backtrack(n+1);

    solution[n] = 4;
    backtrack(n+1);

    // solution[n] = 5;
    // backtrack(n+1);
    //
    // solution[n] = 6;
    // backtrack(n+1);
    //
    // solution[n] = 7;
    // backtrack(n+1);
    //
    // solution[n] = 8;
    // backtrack(n+1);
    //
    // solution[n] = 9;
    // backtrack(n+1);
    //
    // solution[n] = 10;
    // backtrack(n+1);

}

int main(int argv, char* args[]){
    backtrack(0);
    return 0;
}
