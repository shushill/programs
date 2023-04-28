#include <bits/stdc++.h>
using namespace std;

// #define sz size()
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
typedef vector<vs> vvs;
typedef vector<bool> vb;
typedef vector< vb > vvb;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef set<pii> spii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef map<string, int> msi;

bool isValid(vi &a, int k){
    for(int i=0; i <k; ++i){
        if(abs(k-i) == abs(a[i] - a[k]) || a[i] == a[k]){
            return false;
        }
    }
    return true;
}

void Backtrack(vvs &answers, vs &ans, vi& a, int deep){
    if(deep >=ans.size()){
        answers.pb(ans);
        return;
    }
    for(int i=0; i<ans[deep].size(); ++i){
        a[deep] = i;
        if(isValid(a, deep)){
            ans[deep][i] = 'Q';
            Backtrack(answers, ans, a, deep+1);
            ans[deep][i] ='.';
        }

    }
}

vvs solveNQueen(int n){
    vvs answers;
    vi a(n, 0);
    vs ans(n, string(n, '.'));
    Backtrack(answers, ans, a, 0);
    return answers;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //code part

    //N-Queen
    int n =4;
    vvs output = solveNQueen(n);
    for(int i =0; i<output.size(); ++i){
        for(int j=0; j<output[i].size(); ++j){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }





    return 0;
}
