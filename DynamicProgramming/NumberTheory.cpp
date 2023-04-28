#include <bits/stdc++.h>
#include <regex>
using namespace std;

// #define sz size()
// #define beg begin()             //max array size 10^6
// #define end end()
#define mod 1000000007            // prime number  10^9
#define INF 0x3f3f3f3f             // 1061109567 10^9
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

bool prime(int n){       // Time complexity O(sqrt(N))
    if(n<2) return false;
    for(int i=2; i*i<=n; ++i){
        if(n%i==0) return false;
    }
    return true;
}

int sieve[N];
void sieveeratosthenes(int n){   //Time complexity O( nlog(logn) )
    fill(sieve, sieve+n, 0);  // easy to find prime between two number range
    for(int x=2; x*x<=n; ++x){
        if(sieve[x]) continue;
        for(int i=2*x; i<=n; i+=x){
            sieve[i] =x;
        }
    }
    for(int i=2; i<n; ++i){
        if(sieve[i] ==0){
            cout<<i<<endl;
        }
    }
}

void factors(int n){
    vi v;               // O(sqrt(N))
    for(int i=1; i*i<=n; ++i){
        if(n%i==0){
            v.pb(i);
        }
        if(n/i != i){
            v.pb(n/i);
        }
    }
    sort(v.begin(), v.end());
    for(auto &i : v){
        cout<<i<<endl;
    }
}

void primefactorization(int n){
    vi v;                // Time complexity O(sqrt(N))
    for(int i=2; i*i<=n; ++i){
        while(n%i==0){
            v.pb(i);
            n=n/i;
        }
    }
    if(n>1){
        v.pb(n);
    }
    sort(v.begin(), v.end());
    for(auto &i : v){
        cout<<i<<endl;
    }
}

void primefactors(int n){
    vi v;                // Time complexity O(sqrt(N))
    for(int i=2; i*i<=n; ++i){
        if(n%i==0){
            v.pb(i);
            while(n%i==0){
                n=n/i;
            }
        }
    }
    if(n>1){
        v.pb(n);
    }
    sort(v.begin(), v.end());
    for(auto &i : v){
        cout<<i<<endl;
    }
}

int spf[N];
void sieveeratos(int n){
    for(int i=2; i<=n; ++i){
        spf[i] = i;
    }
    for(int i=2; i*i<=n; ++i){
        if(spf[i]==i){
            for(int j=i*2; j<=n; j+=i){
                if(spf[j]==j){
                    spf[j] =i;
                }
            }
        }
    }
}

void primeFactorizationUsingSieve(int n){
    sieveeratos(n);
    vi v;       //Time complexity O(log(N))
    while(n!=1){
        v.pb(spf[n]);
        n=n/spf[n];
    }
    sort(v.begin(), v.end());
    for(auto &i : v){
        cout<<i<<endl;
    }
}

void eulertotient(int n){
    int res =n;         // time complexity O(sqrt(N))
    for(int i=2; i*i<=n; ++i){
        if(n%i==0){
            res -= res/i;
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1){
        res -= res/n;
    }
    cout<<res<<endl;
}
vi p;
void allprime(){
    int n=N;
    for(int i=2; i*i<=n; ++i){
        if(n%i==0){
            p.pb(i);
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1){
        p.pb(n);
    }
}
void eulerTotientUsingSieve(int n){
    // vi v = allprime(n);
    int res =n;        // Time complexity O( sqrt(n/log(n)) )
    sort(p.begin(), p.end());
    for(int i=0; p[i]*p[i]<=n; ++i){
        if(n%p[i] == 0){
            res -=res/p[i];
            while(n%p[i]==0){
                n/=p[i];
            }
        }
    }
    if(n>1){
        res -= res/n;
    }
    cout<<res<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//code part
    int n = 12;
    // int d = log10(n) + 1;      //count of digits
    // cout<<d<<endl;
    // string s = to_string(n);
    // cout<<s.size()<<endl;

    //prime(n) ? cout<<"prime "<<endl : cout<<"non prime"<<endl;
    //sieveeratosthenes(n);
    //factors(n);
    //primefactors(n);
    //primefactorization(n);
    //primeFactorizationUsingSieve(n);
    //eulertotient(n);     //all gcd between [1..n] =1
    //eulerTotientUsingSieve(n);
    //allprime();
    int x = 7;
    cout<<floor(log10(x)+1)<<endl;























	return 0;
}
