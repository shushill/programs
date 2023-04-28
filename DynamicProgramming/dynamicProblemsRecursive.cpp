1
#include <bits/stdc++.h>
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
#define N 1000000


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


// int getsum(int *st, int sa, int se, int qs, int qe, int pos){
//     if(qs<=sa && qe>=se){
//         return st[pos];
//     }
//     if(qs>se || qe<sa){
//         return 0;
//     }
//     int mid = sa + (se-sa)/2;
//     return getsum(st, sa, mid, qs, qe, pos*2+1) + getsum(st, mid+1, se, qs, qe, 2*pos+2);
// }
//
// int constructtree(int *arr, int sa, int se, int *st, int pos){
//     if(sa == se){
//         st[pos] = arr[sa];
//         return arr[sa];
//     }
//     int mid = sa + (se-sa)/2;
//     st[pos] = constructtree(arr, sa, mid, st, pos*2+1)+constructtree(arr, mid+1, se, st, pos*2+2);
//     return st[pos];
//
// }


//  int n;
// int dp[1<<16];
//
//
// int possible(int k, int mask, vi &nums, int cursum, int target){
//     if(mask == ((1<<n)-1)){
//         if(k==0){
//             return 1;
//         }
//         return 0;
//     }
//     if(dp[mask] !=-1){
//         return dp[mask];
//     }
//     int f=0;
//     for(int i=0; i<n; ++i){
//         if(mask&(1<<i)){
//             continue;
//         }
//         if(cursum + nums[i]>target){
//             continue;
//         }
//         else if(cursum +nums[i]==target){
//             f |= possible(k-1, (mask|(1<<i)), nums, 0, target);
//         }else{
//             f |= possible(k, (mask|(1<<i)), nums, cursum+nums[i], target);
//         }
//     }
//     return dp[mask]=f;
// }

// bool possible(string s, string p, int i, int j, vvi &dp){
//     if(j==(int)p.length()){
//         if((int)s.length()==i){
//             return true;
//         }else{
//             return false;
//         }
//     }
//     if(dp[i][j]>=0){
//         return dp[i][j];
//     }
//     bool firstmatch = (i<s.length() && (s[i] == p[j] || p[j]=='.'));
//     bool ans=0;
//     if(j+1<(int)p.length() && p[j+1]=='*'){
//         ans = (possible(s, p, i, j+2, dp) || (firstmatch && possible(s, p, i+1, j, dp)));
//     }else{
//         ans = possible(s, p, i+1, j+1, dp);
//     }
//     return dp[i][j]=ans;
//
// }

// int longestparenthesis(int i, string s, vi &memo){
//     if(i<=0){
//         return 0;
//     }
//     if(memo[i] != -1){
//         return memo[i];
//     }
//     if(s[i]=='('){
//         memo[i]=0;
//     }
//     else if(s[i]==')' && s[i-1]=='('){
//         memo[i]=longestparenthesis(i-2, s, memo) +2;
//     }else if(s[i]==')' && s[i-1]==')'){
//         int len = longestparenthesis(i-1, s, memo);
//         if(i-1-len>=0 && s[i-1-len] == '('){
//             memo[i] = longestparenthesis(i-2-len, s, memo)+len+2;
//         }else{
//             memo[i]=0;
//         }
//     }
//     return memo[i];
// }

// int longestparenthesisdp(string s, vi &memo){
//     if(s.size()<=0){
//         return 0;
//     }
//     int res=0;
//     for(int i=0; i<s.size(); ++i){
//         if(s[i]=='('){
//             memo[i]=0;
//         }
//         else if(s[i]==')' && s[i-1]=='('){
//             memo[i]=memo[i-2]+2;
//         }else if(s[i]==')' && s[i-1]==')'){
//             int len = memo[i-1];
//             if(i-1-len>=0 && s[i-1-len]=='('){
//                 memo[i]=memo[i-2-len] + len+2;
//             }else{
//                 memo[i]=0;
//             }
//         }
//         res = max(res, memo[i]);
//     }
//     return res;
// }


// int kadanebruteapproach(vi &v){
//     int n = v.size();
//     int sum =0;
//     int maxele=-INF;
//     int localmax[n];
//     localmax[0]=v[0];
//     for(int i=1; i<n; ++i){
//         localmax[i] = max(v[i], v[i]+localmax[i-1]);
//     }
//     for(int i=0; i<n; ++i){
//         maxele = max(maxele, localmax[i]);
//     }
//
//     return maxele;
//
// }
// int maxsum;
// int kadanebruteapproach(vi &v, int n, int *localmax){
//     if(n<0){
//         return -INF;
//     }
//     localmax[n] = max(v[n], localmax[n+1]+v[n]);
//     return maxsum = max(localmax[n], kadanebruteapproach(v, n-1, localmax));
//
// }
//
// int cross(vi &v, int l, int mid, int r){
//     int csum=0;
//     int ans1 = -INF;
//     for(int i=mid; i>=l; --i){
//         csum +=v[i];
//         ans1 = max(ans1, csum);
//     }
//     csum=0; int ans2 =-INF;
//     for(int i=mid+1; i<=r; ++i){
//         csum+=v[i];
//         ans2 = max(ans2, csum);
//     }
//     return ans1+ans2;
// }
//

// int kadanedivideconquer(vi &v, int l, int r){
//     if(l>=r){
//         return v[l];
//     }
//     int mid = l+(r-l)/2;
//     int left = kadanedivideconquer(v, l, mid );
//     int right = kadanedivideconquer(v, mid+1, r);
//
//     int midsum = cross(v, l, mid, r);
//     return (max(midsum, max(left, right)));
//
// }

// struct threeinfo{
//     int profit;
//     int ixbuy;
//     int ixsell;
// };
//
//
// threeinfo  stockprice(int ar[], int l, int r){
//     threeinfo xl, yr, z;
//     if(l>=r){
//         z.profit =0;
//         z.ixbuy=l;
//         z.ixsell=r;
//         return (z);
//     }
//     int mid = l + (r-l)/2;
//     xl = stockprice(ar, l, mid);
//     yr = stockprice(ar, mid+1, r);
//     int mmin=ar[l];
//     int ixmin = l;
//     for(int i=l+1; i<=mid; ++i){
//         if(ar[i]<mmin){
//             mmin = ar[i];
//             ixmin = i;
//         }
//     }
//     int mmax =ar[mid];
//     int ixmax = mid;
//     for(int j=mid+1;j<=r; ++j){
//         if(ar[j]>mmax){
//             mmax = ar[j];
//             ixmax = j;
//         }
//     }
//     int proffit = ar[ixmax] - ar[ixmin];
//     z.profit = proffit;
//     z.ixbuy = ixmin;
//     z.ixsell = ixmax;
//     if(xl.profit > max(yr.profit, proffit)){
//         return (xl);
//     }else if(yr.profit > max(xl.profit, proffit)){
//         return (yr);
//     }else{
//         return (z);
//     }
// }

//vector<vvi> memo;

// int buysellstockK1(vi &v, int pos, int k, bool bought){
//     if(pos>=v.size() || k==0){
//         return 0;
//     }
//     if(memo[bought][k][pos] != -1){
//         return memo[bought][k][pos];
//     }
//     int maxprofit =0;
//     maxprofit = max(maxprofit, buysellstockK1(v, pos+1, k, bought));
//     if(bought){
//         maxprofit = max(maxprofit, buysellstockK1(v, pos+1, k-1, false) + v[pos]);
//     }else{
//         maxprofit = max(maxprofit, buysellstockK1(v, pos+1, k, true)-v[pos]);
//     }
//     memo[bought][k][pos] = maxprofit;
//     return maxprofit;
// }
// vi memo;
// int buystockKinfinite(vi &v, int cur, int n){
//     //base case
//     if(cur>=n) return 0;
//     if(memo[cur] != -1){
//         return memo[cur];
//     }
//
//     int maxprofit=0;
//     for(int i=cur+1; i<n; ++i){
//         if(v[cur]<v[i]){
//             int cooldown=0;  // for cooldown days
//             int fee=2; // for transaction fee
//             maxprofit = max(maxprofit, v[i]-v[cur]-fee + buystockKinfinite(v, i+1+cooldown, n));
//         }
//     }
//     maxprofit = max(maxprofit, buystockKinfinite(v, cur+1, n));
//     memo[cur] = maxprofit;
//     return maxprofit;
// }
//

void buysellstockKinfinite(vi &v, int n){
    if(n==1) return;
    int i=0;
    while(i<n-1){
        while((i<n-1) && v[i+1]<=v[i]){
            i++;
        }
        int buy = i++;
        if(i==n-1) break;
        while((i<n)&& v[i]>=v[i-1]){
            i++;
        }
        int sell = i-1;
        cout<<"buy on day "<<buy<<"\n"<<"sell on day "<<sell<<endl;
    }
}
void buysellstockvariation(vi &v, int n){
    //k is fixed
    //k=1;
    // int k=2; // number of transaction (varible)
    // memo.resize(2, vvi(k+1, vi(v.size(), -1)));
    // int profit = buysellstockK1(v, 0, k, false);
    // cout<<"profit "<<profit<<endl;
    //--------------------------------------------------//

    // k is infinite
    //memo.resize(v.size(), -1);
    //int profit = buystockKinfinite(v, 0, n);
    //cout<<"Profit = "<<profit<<endl;

    buysellstockKinfinite(v, n);

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

    // int arr[] = {1, 3, 5, 7, 9, 11};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int l = ceil(log2(n)) ;
    // l = 2*(pow(2, l))-1;
    // int *st = new int[l];
    // constructtree(arr, 0, n-1, st, 0);
    // int qs = 1; int qe = 3;
    // int sum = getsum(st , 0, n-1, qs, qe, 0);
    // cout<<sum<<endl;

    // vi nums = {4, 3, 2, 3, 5, 2, 1};
    // int k=4; int sums=0;
    // for(auto  &i : nums){
    //     sums+=i;
    // }
    // if(sums%k){
    //     cout<<"not possible "<<endl;
    // }
    // n = nums.size();
    // memset(dp, -1, sizeof(dp));
    // if(possible(k, 0, nums, 0, sums/k)){
    //     cout<<"possible "<<endl;
    // }

    // string s = "aab";
    // string p = "c*a*b";
    // vvi dp(s.length()+1, vi(p.length(), -1));
    // if(possible(s, p, 0, 0 , dp)){
    //     cout<<"possible";
    // }else{
    //     cout<<"not possible";
    // }

    // string s =")()())";
    // int n=s.size();
    // vi memo(n, -1); int maxlen=0;
    // // for(int i=0; i<n; ++i){
    // //     maxlen = max(maxlen, longestparenthesis(i, s, memo));
    // // }
    // cout<<longestparenthesisdp(s, memo)<<endl;

    // vi v{-2, 1, -3, 4, -1, 2, 1, -5};
    // int localmax[v.size()];
    // memset(localmax, 0, sizeof(localmax));
    // localmax[v.size()-1] = v[v.size()-1];
    //
    // //int sum = kadanebruteapproach(v, (int)v.size()-2, localmax); O(N)
    // int sum = kadanedivideconquer(v, 0, v.size()-1); O(NlogN)
    // //cout<<max(sum, localmax[v.size()-1])<<endl;
    // cout<<sum<<endl;

    // int ar[] ={7,6,4,3,1};
    // int n = sizeof(ar) / sizeof(ar[0]);
    // threeinfo d = stockprice(ar, 0, n-1);
    // cout<<"profit "<<d.profit<<endl;

    //vi v = {7,1,5,3,6,4};
    vi v ={1, 3, 2, 8, 4, 9};
    //vi v = {7,6,4,3,1};
    //vi v = {1, 2, 3, 4, 5};
    //vi v = {3,2,6,5,0,3};
    //vi v={2, 4, 1};
    //vi v = {1,2,3,0,2};
    //vi v = {3,3,5,0,0,3,1,4};
    int n = v.size();
    buysellstockvariation(v, n);












	return 0;
}
