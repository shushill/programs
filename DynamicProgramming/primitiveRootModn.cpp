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

bool isprime(int n){
    if(n<2) return false;
    for(int i=2; i*i<=n; ++i){
        if(n%i==0) return false;
    }
    return true;
}

int eulertotient(int n){
    int res =n;
    for(int i=2; i*i<=n; ++i){
        if(n%i==0){
            res -= res/i;
            while(n%i==0){
                n = n/i;
            }
        }
    }
    if(n>1){
        res -= res/n;
    }
    return res;
}

vi primefactors(int n){
    vi f;
    for(int i=2; i*i<=n; ++i){
        if(n%i==0){
            f.pb(i);
            while(n%i==0){
                n /=i;
            }
        }
    }
    if(n>1){
        f.pb(n);
    }
    return f;
}

int power(int a, int n, int m){
    int res =1;
    a = a%m;
    while(n>0){
        if(n&1){
            res = (res*a)%m;
        }
        n = n/2;
        a = (a*a)%m;
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
    //primitive root mod n = a^k=1 (mod n) if k = phi(n)
    // if k < phi(n) it is multiplicative order

     int n = 23;
    int phi;
    vi root;
    if(isprime(n)){
        phi = n-1;
    }else{
        phi = eulertotient(n);
    }
    vi v = primefactors(phi);
    for(int i=2; i<=phi; ++i){
        bool flag=false;
        for(int j = 0; j < v.size(); ++j){
            if(power(i, phi/v[j], n)==1){
                flag = true;
                break;

            }

        }
        if(flag == false){
            cout<<i<<endl;
        }
    }












	return 0;
}
