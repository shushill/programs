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
typedef vector<bool> vb;
typedef vector< vb > vvb;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef set<pii> spii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef map<string, int> msi;

vector<string> lettercombination(string &digits){
    vector<string> res;
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.pb("");
    for(int i =0; i<digits.size(); ++i){
        vector<string> temp;
        string chars = charmap[digits[i] - '0'];
        for(int c = 0; c < chars.size(); ++c){
            for(int j=0; j <res.size(); ++j){
                temp.pb(res[j] + chars[c]);
            }
        }
        res = temp;
    }
    return res;
}

void backtrackcomb(vector<string> &res, string& temp, string charmap[], string &digits, int index){
    if(index == digits.size()){
        res.pb(temp);
        return;
    }
    for(int i =0; i<charmap[digits[index]-'0'].size(); ++i){
        temp.pb(charmap[digits[index]-'0'][i]);
        backtrackcomb(res, temp, charmap, digits, index+1);
        temp.pop_back();
    }
}

vector<string> lettercombinationbacktrack(string digits){
    vector<string> res;
    string temp;
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    backtrackcomb(res, temp, charmap, digits, 0);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //code part

    //combinations
    string digits = "23";
    vector<string> res = lettercombination(digits);
    //vector<string> res = lettercombinationbacktrack(digits);
    for( auto &i : res){
        for(auto &j : i){
            cout<<j;
        }
        cout<<endl;
    }



    return 0;
}
