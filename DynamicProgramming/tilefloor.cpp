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


int tilefloor(int n, int m){
    if(n>=1 && n<m) return 1;
    if(n==m) return 2;
    return tilefloor(n-1, m) + tilefloor(n-m, m);
}

int tilefloordp(int n, int m){
    int C[n+1];
    C[0] =0;
    for(int i =1; i<=n; i++){
        if(i<m || i == 1) C[i] = 1;
        if(i == m) C[i] = 2;
        if(i> m) C[i] = C[i-1] + C[i-m];
    }
    return C[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //code part

    //tile a floor
    cout<<tilefloor(7, 4)<<endl;
    cout<<tilefloordp(7, 4)<<endl;



    return 0;
}
