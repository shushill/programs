
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const int N = 1e3+3;
//#define int long long

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int lowerbound(vector<int> &v, int to_find){
    int n = v.size();
    int lo = 0;
    int hi = n-1;
    int mid;
    while(hi-lo>1){
        mid = lo+(hi-lo)/2;
        if(v[mid]<to_find){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }
    if(v[lo]>=to_find){
        return lo;
    }else if(v[hi]>=to_find){
        return hi;
    }else{
        return -1;
    }
}
int higherbound(vector<int> &v, int to_find){
    int n = v.size();
    int lo = 0;
    int hi = n-1;
    int mid;
    while(hi-lo>1){
        mid = lo+(hi-lo)/2;
        if(v[mid]<=to_find){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }
    if(v[lo]>to_find){
        return lo;
    }else if(v[hi]>to_find){
        return hi;
    }else{
        return -1;
    }
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
    vector<int> v(n);
    for(auto &i : v){
        cin>>i;
    }
    int to_find = 5;
    int lb = lowerbound(v, to_find);
    int hi = higherbound(v, to_find);
    cout<<lb<<endl;
    cout<<hi<<endl;


    return 0;
}
