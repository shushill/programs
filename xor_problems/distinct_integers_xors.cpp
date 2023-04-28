
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
const int log_a = 20;
int basis[log_a];
int sz;


// distinct integers that can be represented over a xor over of a subsets

void insertVector(int mask){
	for(int i=0; i<log_a; ++i){
		if(mask & (1<<i) == 0) continue;
		if(!basis[i]){
			basis[i]=mask;
			++sz;
			return;
		}
		mask ^= basis[i];
	}
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		insertVector(n);
	}
	cout<<(1<<sz)<<"\n";






    return 0;
}
