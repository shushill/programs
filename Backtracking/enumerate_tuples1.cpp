#include "C++template.h"

int solution[5];
bool used[5];


void print_solution(){
    for(int i =0; i<3; ++i){
        cout << solution[i] << " ";
    }
    cout << endl;
}

void backtrack(int n){
    if(n == 3){
        print_solution();
        return;
    }

    if(!used[0]){
        used[0] = true;
        solution[n] = 0;
        backtrack(n+1);
        used[0] = false;
    }
    if(!used[1]){
        used[1] = true;
        solution[n] = 1;
        backtrack(n+1);
        used[1] = false;
    }
    if(!used[2]){
        used[2] = true;
        solution[n] = 2;
        backtrack(n+1);
        used[2] = false;
    }
}

int main(int argv, char* args[]){
    fill(used, used+5, false);
    backtrack(0);
    return 0;
}
