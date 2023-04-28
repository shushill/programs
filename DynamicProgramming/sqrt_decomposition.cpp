
#include<bits/stdc++.h>
using namespace std;

// const int mod = 1e9+7;
// const int inf = 0x3f3f3f3f;
// const int N = 1e3+3;
//#define int long long

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>


int getmin(int l, int r, int a[], int n){
    int blk = floor(sqrt(n));
    int lb = l/blk;
    int rb = r/blk;
    int num = n/blk;
    vector<int> b(num, 1000000);
    int c=-1;
    for(int i=0; i<n; ++i){
        if(i%(blk) == 0){
            c++;
        }
        b[c]=min(a[i], b[c]);
    }
    int mn = INT_MAX;
    if(lb==rb){
        for(int i=l; i<=r; ++i){
            mn = min(mn, a[i]);
        }
    }
    else{
        for(int i=l; i<blk*(lb+1); ++i){
            mn = min(mn, a[i]);
        }
        for(int i=lb+1; i<rb; ++i){
            mn = min(mn, b[i]);
        }
        for(int i = blk*rb; i<=r; ++i){
            mn = min(mn, a[i]);
        }
    }

    return mn;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif

    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    int q; cin>>q;
    for(int i=0; i<q; ++i){
        int l, r; cin>>l>>r;
        --l; --r;
         int ans = getmin(l, r, a, n);
         cout<<ans<<endl;
    }




    return 0;
}
