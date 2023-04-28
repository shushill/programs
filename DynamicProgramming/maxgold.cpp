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

int getMaxGold(int goldtable[N][N], int m, int n){
    int right_up, right, right_down;
    int res, i, j;
    int gold[m][n];
    memset(gold, 0, sizeof(gold));
    for(int col = n-1; col>=0; col--){
        for(int row = 0; row <m; row++){
            right_up = (row == 0 || col == n-1) ? 0 : gold[row-1][col+1];
            right = (col == n-1) ? 0 : gold[row][col+1];
            right_down = (col==n-1 || row == m-1) ? 0: gold[row+1][col+1];
            gold[row][col] = goldtable[row][col] + max(right, max(right_up, right_down));
        }
    }
    res = gold[0][0];
    for(int i = 1; i < m; ++i){
        res = max(res, gold[i][0]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //code part

    //max gold to obtain

    int gold[N][N]= {
        {1, 3, 1, 5},
        {2, 2, 4, 1},
        {5, 0, 2, 3},
        {0, 6, 1, 2}
    };
    int m = 4, n = 4;
    cout << getMaxGold(gold, m, n)<<endl;



    return 0;
}
