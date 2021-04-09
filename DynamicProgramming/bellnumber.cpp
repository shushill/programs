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


int countsetrecur(int n, int k){

    if(n==0|| k==0|| k>n) return 0;

    if(k==1 || k==n ) return 1;

    return k*countsetrecur(n-1, k) + countsetrecur(n-1, k-1);
}

int countsettable(int n, int k){
    int dp[n+1][k+1];
    for(int i =0; i <= n; ++i){
        dp[i][0] = 0;
    }
    for(int i =0; i <= k; ++i){
        dp[0][k] = 0;
    }
    for(int i=1; i<=n; ++i){
        for(int j =1; j<=i; ++j){
            if(j == i || j == 1){
                dp[i][j] = 1;
            }else{
                dp[i][j] = j*dp[i-1][j] + dp[i-1][j-1];
            }
        }
    }
    for(int i=0; i<=n; ++i){
        for(int j =0; j<=i; ++j){
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
    return dp[n][k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //code part
    cout<<countsetrecur(3, 2)<<endl;
    cout<<countsettable(3, 2);






    return 0;
}
