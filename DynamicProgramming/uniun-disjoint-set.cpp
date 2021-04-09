
#include <bits/stdc++.h>
using namespace std;

// #define sz size()
// #define beg begin()
// #define end end()
#define mod 1000000007
#define INF 0x3f3f3f3f //1061109567
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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
typedef vector<bool> vb;
typedef vector< vb > vvb;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef map<string, int> msi;
typedef vector<pii> vpii;
typedef set<pii> spii;
typedef set<int> si;
typedef map<string, int> msi;


void make_set(int i, vi &par, vi &sz){
    par[i]=i;
    sz[i] = 1;
}
int find_set(int n, vi &par){
    if(n==par[n]){
        return n;
    }
    return par[n] = find_set(par[n], par); //path compression
}

void uniun_set(int n1, int n2, vi &par, vi &sz){
    int a = find_set(n1, par);
    int b = find_set(n2, par);
    if(a == b){
        cout<<"Uniun not possible"<<endl;
    }
    if(sz[a]<sz[b]){
        swap(a, b);     // choose a as always a bigger number
    }
    par[b]=a;
    sz[a] = sz[a]+sz[b];    //union by size

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    //code part
    // 10^6 in 1 sec is the computation limit of this laptop
    // 10^(7, 8) is the computation limit of codeforces



    int vertices; int edge;
    cin>>vertices>>edge;
    vi par(vertices+1);
    vi sz(vertices+1);
    for(int i=1; i<=vertices ; ++i){
        make_set(i, par, sz);
    }
    pair<int, pii > edgeslist[edge+1];
    for(int i=1; i<=edge; ++i){
        int startinx, endinx, weight;
        cin>>startinx>>endinx>>weight;
        edgeslist[i] = {weight, {startinx, endinx}};
    }
    sort(edgeslist, edgeslist+edge+1);
    int min_cost =0;
    for(int i=1; i<=edge; ++i){
        int st, en, w;
        st = edgeslist[i].second.first;
        en = edgeslist[i].second.second;
        w = edgeslist[i].first;
        st = find_set(st, par);
        en = find_set(en, par);
        if(st != en){     // to avoid a cycle in selecting a edge of graph
            min_cost +=w;
            uniun_set(st, en, par, sz);
        }
    }
    cout<<min_cost<<endl;



}
