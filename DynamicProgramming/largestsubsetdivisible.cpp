#include <bits/stdc++.h>
#include <regex>
using namespace std;

// #define sz size()
// #define beg begin()
// #define end end()
#define mod 1000000007
#define INF 0x3f3f3f3f
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

int largestSubset(int a[], int n){
    sort(a, a+n);
    int dp[n];
    dp[n-1] =1;
    
    for(int i=n-2; i>=0; --i){
        int m =0;
        for(int j=i+1; j<n; ++j){
            if(a[j]%a[i] == 0){
                m = max(m, dp[j]);
            }
        }
        dp[i] = 1+m;
    }
    return *max_element(dp, dp+n);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//code part

    int a[] = { 5,7, 18 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << largestSubset(a, n) << endl;





	return 0;
}
