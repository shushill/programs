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

int friendspairingcount(int n){
    int dp[n+1];
    for(int i =0; i <=n; ++i){
        dp[i] =0;
    }
    for(int i =0; i <=n; ++i){
        if(i<=2) dp[i] = i;
        else{
            dp[i] = dp[i-1] + (i-1)*dp[i-2];
        }
    }
    return dp[n];
}

int friendspairingcounttable(int n){
    int dp[n+1];
    memset(dp, -1 , sizeof(dp));
    if(dp[n] !=  -1) return dp[n];
    if(n>2){
        return dp[n] = friendspairingcounttable(n-1) + (n-1)*friendspairingcounttable(n-2);
    } else{
        return dp[n] = n;
    }
}

int friendsoptimised(int n){
    int b = 2 ; int a = 1;
    int c = 0;
    if(n<=2) return n;
    for(int i = 3; i <=n; ++i){
        c = b + (i-1)*a;
        a = b;
        b = c;
    }
    return c;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //code part

    //friends pairing
    cout<<friendspairingcount(4)<<endl;
    cout<<friendspairingcounttable(4)<<endl;
    cout<<friendsoptimised(4)<<endl;







    return 0;
}
