#include <bits/stdc++.h>
#include <regex>
using namespace std;

// #define sz size()
// #define beg begin()             //max array size 10^6
// #define end end()
#define mod 1000000007            // prime number  10^9
#define INF 0x3f3f3f3f             // 1061109567 10^9
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define endl "\n"
#define eps 1e-9
#define sqr(x) ((x)*(x))
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define pb push_back
#define N 10000

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<char> vc;
typedef vector< vc > vvc;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<bool> vb;
typedef vector< vb > vvb;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef map<string, int> msi;

void multiply(int a[3][3], int b[3][3]){
    int mul[3][3];
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            mul[i][j]=0;
            for(int k=0; k<3; ++k){
                mul[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    for(int i=0; i<3; ++i){
        for(int j =0; j<3;++j){
            a[i][j]=mul[i][j];
        }
    }
}

int powerth(int p[3][3], int n){
    int m[3][3] = {
        {1, 1, 1},
        {1, 0, 0},
        {0, 1, 0}
    };
    if(n==1){
        return p[0][0] + p[0][1];
    }
    powerth(p, n/2);
    multiply(p, p);
    if(n%2!=0){
        multiply(p, m);
    }
    return p[0][0]+p[0][1];
}

int nthterm(int n){
    int f[3][3] = {
        {1, 1, 1},
        {1, 0, 0},
        {0, 1, 0}
    };

    if(n==0){
        return 0;
    }if(n==1 || n==2){
        return 1;
    }
    int k = powerth(f, n-2);
    return k;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//code part
    //find nth fibnacci term;
    int n=5;
    cout<<nthterm(n)<<endl;









	return 0;
}
