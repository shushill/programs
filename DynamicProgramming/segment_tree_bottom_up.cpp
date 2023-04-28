
#include <bits/stdc++.h>
using namespace std;
#define int long long
//const int INF = (int)numeric_limits<int>::max();
const int inf = 1e17+7;

const int N = 1e6+5;
int n, m;
struct node{
    int value=0;
    int level=0;
    node(){
        value=level=0;
    }
};
node tree[4*N];


node merge(node a, node b){
    node temp;
    temp.level = a.level+1;
    if(temp.level & 1){
        temp.value = a.value ^ b.value;
    }else{
        temp.value = a.value | b.value;
    }
    return temp;
}

void build(std::vector<int> &arr){
    for(int i=0; i<(1<<n); ++i){
        tree[i+(1<<n)].value=arr[i];
        tree[i+(1<<n)].level=1;
    }
    for(int i = (1<<n)-1; i>0; --i){
        tree[i]=merge(tree[i<<1], tree[i<<1|1]);
    }
}

int query(int pos, int val){
    tree[(1<<n)+pos].value = val;
    for(int i = (1<<n)-1; i>0; --i){
        tree[i]=merge(tree[i<<1], tree[i<<1|1]);
    }
    // for(int l +=(1<<n), r+=(1<<n); l<r; l>>=1, r>>=1){
    //     node al, ar;
    //     if(l& 1){
    //         al = merge(al, tree[l++]);
    //     }else{
    //         ar = merge(ar, tree[--r]);
    //     }
    // }
    // node ans = merge(al, ar);
    // return ans.
    return tree[1].value;
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //free codechef
    cin>>n>>m;
    vector<int> arr;
    arr.resize(1<<n);
    for(int i=0; i<(1<<n); ++i){
        cin>>arr[i];
    }
    build(arr);
    for(int i=0; i<m; ++i){
        int pos, val;
        cin>>pos>>val;
        --pos;
        cout<<query(pos, val)<<"\n";

    }















    return 0;
}
