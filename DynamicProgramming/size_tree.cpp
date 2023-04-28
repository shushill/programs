
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

void dfs(int node, int par, vector<int> tree[], int sub[]){
    sub[node]=1;
    for(int child : tree[node]){
        if(child != par){
            dfs(child, node, tree, sub);
            sub[node]+=sub[child];
        }
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

    int n, m; cin>>n>>m;
    vector<int> tree[n];
    int sub[n];
    for(int i=0; i<n; ++i){
        sub[i]=0;
    }

    for(int i=0; i<m; ++i){
        int x, y; cin>>x>>y;
        --x; --y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
     dfs(4, -1, tree, sub);
    cout<<sub[n-1]<<endl;



    return 0;
}
