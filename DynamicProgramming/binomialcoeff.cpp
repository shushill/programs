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


int binomialcoeff(int n, int k){

    if(k==0 || k == n) return 1;

    return binomialcoeff(n-1, k-1) + binomialcoeff(n-1, k);
}

int binomialtable(int n, int k){
    int c[n+1][k+1];
    int i, j;
    for(i =0; i <=n; ++i){
        for(j=0; j<=min(i, k); ++j){
            if(j==0 ||j == i) {
                c[i][j] = 1;
            }else{
                c[i][j] = c[i-1][j-1] + c[i-1][j];
            }
        }
    }
    return c[n][k];
}

int binomialoptimised(int n, int k){
    int c[k+1];
    int i, j;
    for(int i=0; i <=n; ++i){
        c[i] =0;
    }
    c[0] = 1;
    for( i =1; i <=n; ++i){
        for(j=min(i,k); j>0; --j){
            c[j] = c[j] + c[j-1];
        }
    }
    return c[k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //code part
    cout<<binomialcoeff(5, 2)<<endl;
    cout<<binomialtable(5, 2)<<endl;
    cout<<binomialoptimised(5, 2)<<endl;





    return 0;
}
