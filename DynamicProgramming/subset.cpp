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


bool subsetsum(int set[], int sz, int sum){
    if(sum == 0) return true;
    if(sz == 0 && sum != 0) return false;
    if(set[sz - 1] > sum) return subsetsum(set, sz-1, sum);
    return subsetsum(set, sz-1, sum) || subsetsum(set, sz-1, sum - set[sz-1]);


}

bool subsetsumTable(int set[], int sz, int sum){
    int subseet[sz+1][sum+1];
    for(int i =0; i<=sz; ++i){
        subseet[i][0] = true;
    }
    for(int i = 1; i<=sum; ++i){
        subseet[0][i] = false;
    }
    for(int i =1; i<=sz; ++i){
        for(int j =1; j<=sum; ++j){
            if(set[i-1] > j){
                subseet[i][j] = subseet[i-1][j];
            }else{
                subseet[i][j] = subseet[i-1][j] || subseet[i-1][j-set[i-1]];
            }
        }
    }

    for(int i =0; i<=sz; ++i){
        for(int j =0; j<=sum; ++j){
            cout<<subseet[i][j]<<" ";
        }
        cout<<endl;
    }

    return subseet[sz][sum];
}

bool subsetoptimised(int set[], int sz, int sum){
    int subset[2][sum+1];
    int i,j;
    for(i = 0; i <=sz; ++i){
        for(j = 0; j<=sum; ++j){
            if(j==0){
                subset[i%2][j] = true;
            }
            else if(i==0){
                subset[i%2][j] = false;
            }
            else if(j>=set[i-1]){
                subset[i%2][j] = subset[(i+1)%2][j] || subset[(i+1)%2][j-set[i-1]];
            }else{
                subset[i%2][j] = subset[(i+1)%2][j];
            }
        }
    }
    return subset[sz%2][sum];
}

int subsetsumdivisible(int set[], int sz, int m){
    int sum=0;
    for(int i =0; i<sz; ++i){
        sum +=set[i];
    }
    int subset[sz+1][sum+1];
    for(int i=0; i<=sz; ++i){
        for(int j=0; j<=sum;++j){
            subset[i][j] =0;
        }
    }
    for(int i=0; i<=sz; ++i){
        subset[i][0] =1;
    }
    for(int i=1; i<=sz; ++i){
        for(int j=0; j<=sum; ++j){
            if(subset[i-1][j] !=0){
                subset[i][j+set[i-1]] = subset[i-1][j] + subset[i-1][j+set[i-1]];
            }
        }
        // cout<<"Before "<<endl;
        // for(int j=0; j<=sum; ++j){
        //     cout<<subset[i][j]<<" ";
        // }
        // cout<<endl;
        for(int j=0;j<= sum;j++){
            subset[i][j]=max(subset[i-1][j], subset[i][j]);
        }
        // cout<<"After "<<endl;
        // for(int j=0; j<=sum; ++j){
        //     cout<<subset[i][j]<<" ";
        // }
        // cout<<endl;
    }
    int count =0;
    for(int i= 0; i<=sum; ++i){
        if(i % m == 0){
            count += subset[sz][i];
        }
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //code part

    //subsetsum
    int set[] = { 2,3,3,1 };
    int sz = (*(&set + 1) - set);
    int sum = 9;
    int m = 6;
    // (subsetsum(set, sz, sum )) ? cout<<"possible"<<endl: cout<<"Not possible"<<endl;
    //(subsetsumTable(set, sz, sum )) ? cout<<"possible"<<endl: cout<<"Not possible"<<endl;
    //(subsetoptimised(set, sz, sum )) ? cout<<"possible"<<endl: cout<<"Not possible"<<endl;
    cout<<subsetsumdivisible(set, sz, m)<<endl;




    return 0;
}
