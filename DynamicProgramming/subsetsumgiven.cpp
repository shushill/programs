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

void backtrack(vvi& finalset, vi& inputset, int key, vi& ccomb, int csum, int pos){
    if(csum > key) return;
    if(pos == inputset.size()) return;
    if(csum == key){
        finalset.pb(ccomb);
        return;
    }
    backtrack(finalset, inputset, key, ccomb, csum, pos+1);
    ccomb.pb(inputset[pos]);
    backtrack(finalset, inputset, key, ccomb, csum+inputset[pos], pos);
    ccomb.pop_back();
}

void backtrackk(vvi& finalset, vi& inputset, int key, vi& ccomb, int csum, int pos){
    if(csum > key) return;
    if(csum == key){
        finalset.pb(ccomb);
        return;
    }
    if(pos == inputset.size()) return;


    ccomb.pb(inputset[pos]);
    backtrackk(finalset, inputset, key, ccomb, csum+inputset[pos], pos+1);
    ccomb.pop_back();
    int end = pos;
    while(end+1<inputset.size() && inputset[end] == inputset[end+1]) {
        ++end;
    }
    backtrackk(finalset, inputset, key, ccomb, csum, end+1);

}

vvi combinationset(vi& inputset, int key){
    vvi finalset;
    vi ccomb;
    backtrackk(finalset, inputset, key, ccomb, 0, 0);
    return finalset;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //code part

    //subsetsumgivensum
    vi inputset;
    inputset.pb(2);
    inputset.pb(3);
    inputset.pb(1);
    inputset.pb(1);
    // inputset.pb(10);
    // inputset.pb(1);
    // inputset.pb(2);
    // inputset.pb(7);
    // inputset.pb(6);
    // inputset.pb(1);
    // inputset.pb(5);

    int key =3;
    sort(inputset.begin(), inputset.end());
    vvi finalsset = combinationset(inputset, key);

    if(finalsset.size() == 0){
        cout<<"No possible combinations"<<endl;
        return 0;
    }
    for(int i =0; i<finalsset.size(); ++i){
        for(int j=0; j<finalsset[i].size();++j){
            cout<<finalsset[i][j]<<" ";
        }
        cout<<endl;
    }




    return 0;
}
