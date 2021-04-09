#include <bits/stdc++.h>
using namespace std;

#define sz size()
//#define beg begin()
//#define end end()
#define mod 1000000007
#define inf 0x3f3f3f3f
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define F first
#define S second
#define endl "\n"
#define eps 1e-9
#define sqr(x) ((x)*(x))
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define pb push_back
#define N 100

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<char> vc;
typedef vector< vc > vvc;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector< vb > vvb;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef set<pii> spii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef map<string, int> msi;


int maxdivide(int a, int b){
    while(a%b == 0){
         a =a/b;
    }
    return a;
}

int isUgly(int no){
    no = maxdivide(no, 2);
    no = maxdivide(no, 3);
    no = maxdivide(no, 5);
    return ((no==1) ? 1 : 0);
}

int nthuglynum(int n){
    int i =1;
    int count =1;
    while (n>count) {
        i++;
        if(isUgly(i)){
            count++;
        }
    }
    return i;
}

int dpuglynum(int n){
    int ugly[n];
    unsigned i2 =0, i3 =0, i5=0;
    unsigned next_multiple_two = 2;
    unsigned next_multiple_three = 3;
    unsigned next_multiple_five = 5;
    unsigned next_num = 1;
    ugly[0] =1;
    for(int i =1; i <n; ++i){
        next_num = min(next_multiple_two, min( next_multiple_three, next_multiple_five));
        ugly[i] = next_num;
        if(next_num == next_multiple_two){
            i2 +=1;
            next_multiple_two = 2*ugly[i2];
        }
        if(next_num == next_multiple_three){
            i3 +=1;
            next_multiple_three = 3*ugly[i3];
        }
        if(next_num == next_multiple_five){
            i5 +=1;
            next_multiple_five = 5 *ugly[i5];
        }
    }
    return next_num;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //code part
    int n=6;
    //int num = nthuglynum(n);
    int num = dpuglynum(n);
    cout<<num<<endl;





    return 0;
}
