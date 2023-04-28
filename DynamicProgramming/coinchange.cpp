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

int coinchangeways(int a[], int s, int n ){

    if(n<0) return 0;
    if(s<=0 && n>0) return 0;
    if(n==0) return 1;

    return coinchangeways(a, s-1, n) + coinchangeways(a, s, n-a[s-1]);

}

int coinchangewaysTable(int a[], int s, int n){
    int c[n+1][s];
    int i, j,x, y;
    for( i = 0; i <s; ++i){
        c[0][i] = 1;
    }
    for(i = 1; i<n+1; ++i){
        for(j =0; j<s; ++j){
            x = (i - a[j]) >=0 ? c[i - a[j]][j] : 0;
            y = (j>=1) ? c[i][j-1] : 0;
            c[i][j] = x+y;
        }
    }
    return c[n][s-1];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //code part

    //max gold to obtain
    int a[] = {1, 2, 3};
    int s = (*(&a + 1) - a);
    cout<<coinchangeways(a, s, 4)<<endl;
    cout<<coinchangewaysTable(a, s, 4)<<endl;






    return 0;
}
