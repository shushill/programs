#include "C++template.h"
namespace abc{
    using namespace::std;
char s[3] ={'a', 'b', 'c'};
bool used[3];
char solution[3];
int Num;

void backtrack(int n, int Num){
    if(n == Num){
        for(int i =0; i <Num; ++i){
            cout << solution[i]<< " ";
        }
        cout << endl;
        return ;
    }
    for(int i =0; i < Num; ++i){
        if(!used[i]){
            used[i] = true;
            solution[n] = s[i];
            backtrack(n+1, Num);
            used[i] = false;
        }
    }
}
}

namespace abb{
    using namespace std;
char s[3] ={'a', 'b', 'b'};
bool used[3];
char solution[3];
int Num;

void backtrack(int n, int Num){
    if(n == Num){
        for(int i =0; i <Num; ++i){
            cout << solution[i]<< " ";
        }
        cout << endl;
        return ;
    }
    char last_letter = '\0';
    for(int i =0; i < Num; ++i){
        if(!used[i]){
            if(s[i] != last_letter){
            last_letter = s[i];
            used[i] = true;
            solution[n] = s[i];
            backtrack(n+1, Num);
            used[i] = false;
            }
        }
    }
}
}

int main(){
    using namespace::abb;
    for(int i =0; i<Num; i++) used[i] = false;
    backtrack(0, 3);
    return 0;
}
