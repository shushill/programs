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

void display(vi &vv){
    for(auto &i : vv){
        cout<<i<<" ";
    }
    cout<<endl;
}

void printsubsetrecur(int arr[], int i, int sum, vi &p, bool **d){
    if ( i==1 && sum !=0 && d[i][sum]){
        p.pb(arr[i-1]);
        display(p);
        return;
    }
    if( i==1 && sum ==0){
        display(p);
        return;
    }
    if(d[i-1][sum]){
        vi b =p;
        printsubsetrecur(arr, i-1, sum, b, d);
    }
    if(sum>=arr[i-1] && d[i-1][sum-arr[i-1]]){
        p.pb(arr[i-1]);
        printsubsetrecur(arr, i-1, sum-arr[i-1], p, d);
    }
}

void printAllSubsets(int arr[], int n, int sum){
    if(n <=0 || sum <0){
        return;
    }

    bool **a = new bool*[n+1];
    for(int i=0; i<n+1; ++i){
        a[i] = new bool[sum+1];
    }
    for(int i=0; i<n+1; ++i){
        a[i][0] = true;
    }
    for(int i=1; i<=sum; ++i){
        a[0][i] = false;
    }
    for(int i=1; i<=n; ++i){
        for(int j= 1; j<=sum; ++j){
            if(arr[i-1] <= j){
                a[i][j] = a[i-1][j] || a[i-1][j-arr[i-1]];
            }else{
                a[i][j] = a[i-1][j];
            }
        }
    }
    if(a[n][sum] == false){
        cout<<"No subset"<<endl;
        return;
    }
    vi p;
    printsubsetrecur(arr, n, sum, p, a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //code part

    //print subset for given sum
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 10;
    printAllSubsets(arr, n, sum);



    return 0;
}
