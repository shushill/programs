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

int permutation(int n, int k){
    if(k>n ) return 0;
    if(k == 0 || k==n) return 1;

    return k*permutation(n-1, k-1) + permutation(n-1, k);
}

int permutationdp(int n , int k){
    int P[n+1][k+1];
    for(int i =0; i <=n; ++i){
        for(int j =0; j<=min(i, k); ++j){
            if(j == 0){
                P[i][j] = 1;
            }else{
                P[i][j] = P[i-1][j-1]*j + P[i-1][j];
            }
            P[i][j + 1] = 0;
        }
    }
    return P[n][k];
}

int permutationoptimized(int n, int k){
    int fact[n+1];
    fact[0] =1;
    for(int i=1; i<=n; ++i){
        fact[i] = fact[i-1]*i;
    }
    return fact[n]/fact[n-k];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //code part

    cout<<permutation(10, 2)<<endl;
    cout<<permutationdp(10, 2)<<endl;
    cout<<permutationoptimized(10, 2)<<endl;




    return 0;
}
