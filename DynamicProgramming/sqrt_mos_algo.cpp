
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

int a[300000];
const int block = 555;
struct query{
    int l;
    int r;
    int inx;
};
query Q[300001];
int ans[300001];
int fre[300001];
int freoffre[300001];
int curmax=0;

bool comp(query a, query b){
    if(a.l/block != b.l/block){
        return a.l/block < b.l/block;
    }
    return a.r < b.r;
}

void add(int pos){
    int pref = fre[a[pos]];
    fre[a[pos]]++;
    int curf = fre[a[pos]];
    freoffre[pref]--;
    freoffre[curf]++;
    if(curf>curmax){
        curmax=curf;
    }
}

void remove(int pos){
    int pref = fre[a[pos]];
    fre[a[pos]]--;
    int curf = fre[a[pos]];

    freoffre[pref]--;
    freoffre[curf]++;
    if(curf<curmax){
        while(freoffre[curmax]==0){
            curmax--;
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

    int n, q; cin>>n>>q;
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    for(int i=0; i<q; ++i){
        cin>>Q[i].l>>Q[i].r;
        Q[i].inx=i;
        Q[i].l--;
        Q[i].r--;
    }
    sort(Q, Q+q, comp);
    int currentl =0; int currentr = -1;
    for(int i=0; i<q; ++i){
        int L = Q[i].l;
        int R = Q[i].r;
        while(currentl>L){
            currentl--; add(currentl);
        }
        while(currentl<L){
            remove(currentl); currentl++;
        }
        while(currentr<R){
            currentr++; add(currentr);
        }
        while(currentr>R){
            remove(currentr); currentr--; 
        }
        int total = Q[i].r - Q[i].l +1;
        int rem = total - curmax;
        int half = (total +1)/2;
        if(curmax <= half){
            ans[Q[i].inx]=1;
        }else{
            ans[Q[i].inx]= total - 2*rem;
        }

    }
    for(int i=0; i<q; ++i){
        cout<<ans[i]<<"\n";
    }






    return 0;
}
