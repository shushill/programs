
#include<bits/stdc++.h>
using namespace std;

// const int mod = 1e9+7;
 const int inf = 0x3f3f3f3f;
// const int N = 1e3+3;
//#define int long long

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif

    vector<int> a({1, 4, 2, 5, 3, 6, 9, 7});
    int n = a.size();
    // vector<int> d(n, 1), p(n, -1);
    // for(int i=0; i<n; ++i){
    //     for(int j=0; j<i; ++j){
    //         if(a[j]<a[i] && d[i]<d[j]+1){
    //             d[i]=d[j]+1;
    //             p[i]=j;
    //         }
    //     }
    // }
    // int ans=d[0], pos=0;
    // for(int i=1; i<n; ++i){
    //     if(d[i]>ans){
    //         ans = d[i];
    //         pos=i;
    //     }
    // }
    // vector<int> subseq;
    // while(pos != -1){
    //     subseq.push_back(a[pos]);
    //     pos=p[pos];
    // }
    // reverse(subseq.begin(), subseq.end());
    // for(auto i : subseq){
    //     cout<<i<<endl;
    // }


    //nlogn
    vector<int> d(n+1, inf);
    d[0]=-inf;

    for(int i=0; i<n; ++i){
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if(d[j-1]<a[i] && a[i]<d[j]){
            d[j]=a[i];
        }
    }
    int ans=0;
    for(int i=0; i<=n; ++i){
        if(d[i]<inf){
            ans =i;
        }
    }
    for(int i=1; i<=ans; ++i){
        cout<<d[i]<<endl;
    }

    return 0;
}
