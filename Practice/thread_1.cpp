#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void func(int n){
    for(int i =0; i<n; ++i){
        cout<<" thread func"<<endl;
    }
}
class funcObj{
public:
    void operator()(int n){
        // for(int i =0; i<n; ++i){
        //     cout<<" thread func"<<endl;
        // }
        cout<<this_thread::get_id()<<endl;
    }
};

int add(int x, int y){
    int z = x+y;
    return z;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // code part
    thread t((funcObj()), 3);
    // for(int i =0; i<3; ++i){
    //     cout<<" Main func"<<endl;
    // }
    cout<<endl;
    cout<<this_thread::get_id()<<endl;
    t.join();
    int a = 5;
    int b = [&] ()->int {
          a = 22;
        return a+1;
    }();
    cout<<"Exit main func  "<<b<<" "<<a<<endl;
    std::function<int(int, int)> f =
    [](int x, int y)->int{
        int z = x+y;
        return z;
    };

    int k = f(31, 9);
    cout<<k;
    return 0;
}
