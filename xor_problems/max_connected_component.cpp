
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
const int log_a = 20;
int basis[log_a];
int sz;



void insertVector(int mask){
	for(int i=0; i<log_a; ++i){
		if(!(mask & (1<<i))) continue;
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
	int n, k;
	while(t--){
		 cin>>k>>n;
		for(int i=0; i<log_a; ++i){
			basis[i]=0;
		}
		 sz=0;
		for(int i=0; i<n; ++i){
			int x; cin>>x;
			insertVector(x);
		}
		int comp = k-sz;
		cout<<(1<<comp)<<"\n";


	}







    return 0;
}
