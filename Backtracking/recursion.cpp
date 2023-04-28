#include "C++template.h"

bool solution[3][3];
void recursion(int x, int y){
    if(y == 3) {
        x++, y =0;
    }
    if(x==3){
        for(int i =0; i< 3; ++i){
            for(int j =0; j<3; ++j){
                cout <<solution[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    solution[x][y] = true;
    recursion(x, y+1);

    solution[x][y] = false;
    recursion(x, y+1);

}

int main(){
    recursion(0, 0);
    return 0;
}
