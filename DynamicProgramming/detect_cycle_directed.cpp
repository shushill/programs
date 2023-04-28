
#include <bits/stdc++.h>
using namespace std;
//const int INF = (int)numeric_limits<int>::max();

bool iscycleutil(vector<int> adj[], vector<bool> visited, int cur){
	if(visited[cur]){
		return true;
	}
	visited[cur]=false;
	bool flag = false;
	for(int i=0; i<adj[cur].size(); ++i){
		flag = iscycleutil(adj, visited, adj[cur][i]);
		if(flag){
			return true;
		}
	}
	return false;
}

bool iscycle(int v, vector<int> adj[]){
	vector<bool> visited(v, false);
	bool flag = false;
	for(int i=0; i<v; ++i){
		visited[i] = true;
		for(int j=0; j<adj[i].size(); ++j){
			flag = iscycleutil(adj, visited, adj[i][j]);
			if(flag){
				return true;
			}
		}
		visited[i]=false;
	}
	return false;
}



signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //free codechef

	int t; cin>>t;
	while(t--){
		int v, e;
		cin>>v>>e;
		vector<int> adj[v];
		for(int i=0; i<e; ++i){
			int x, y;
			cin>>x>>y;
			--x; --y;
			adj[x].push_back(y);
		}
		if(iscycle(v, adj)){
			cout<<"cycle"<<"\n";
		}
		else cout<<"no cycle"<<"\n";
	}









    return 0;
}
