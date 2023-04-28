
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


int n, m;
const int maxn=4;
void dfs(int node, int par, int lvl, int level[], int lca[][maxn+1], vector<int> v[]){
    level[node]=lvl;
    lca[node][0]=par;
    for(int child : v[node]){
        if(child != par){
            dfs(child, node, lvl+1, level, lca, v);
        }
    }
}
int getlca(int a, int b, int level[], int lca[][maxn+1]){

    if(level[b]<level[a]){
        swap(a, b);
    }
    int d = level[b]-level[a];
    while(d>0){
        int i = log2(d);
        b = lca[b][i];
        d-=(1<<i);
    }
    if(a == b){
        return a;
    }
    for(int i=maxn; i>=0; --i){
        if(lca[a][i] != -1 && (lca[a][i] != lca[b][i])){
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    return lca[a][0];
}
int getdist(int a, int b, int level[], int lca[][maxn+1], vector<int> v[]){
    int lc = getlca(a, b, level, lca);
    int dis = level[a]+level[b]-2*level[lc];
    return dis;
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif

    cin>>n>>m;
    vector<int> v[n];
    for(int i=0; i<m; ++i){
        int x, y;
        cin>>x>>y;
        --x; --y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int level[n];
    //static int maxn = ceil(log2(n));
    int lca[n][maxn+1];
    for(int i=0; i<=maxn; ++i){
        for(int j=0; j<n; ++j){
            lca[j][i]=-1;
        }
    }
    int src = 0;
    dfs(src, -1, 0, level, lca, v);
    for(int i=1; i<=maxn; ++i){
        for(int j=1; j<n; ++j){
            if(lca[j][i-1] != -1){
                int par = lca[j][i-1];
                lca[j][i]=lca[par][i-1];
            }
        }
    }

    int q; cin>>q;
    while(q--){
        int a, b;
        cin>>a>>b;
        --a; --b;
        int ans = getdist(a, b, level, lca, v);
        cout<<ans<<endl;
    }

    







    return 0;
}
