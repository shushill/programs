
#include <bits/stdc++.h>
using namespace std;
//const int INF = (int)numeric_limits<int>::max();

int v, e;

void dfs(int u, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, vector<pair<int, int>> &bridge, vector<int> &parent ){
	static int time =0;
	disc[u]=low[u]=time;
	time++;
	for(int v : adj[u]){
		if(disc[v]== -1){
			parent[v]=u;
			dfs(v, adj, disc, low, bridge, parent);
			low[u] = min(low[u], low[v]);

			if(low[v]>disc[u]){
				bridge.push_back({u, v});
			}

		}
		else if(v != parent[u]){
			low[u] = min(low[u], disc[v]);
		}
	}

}

void find_bridge_tarjan(vector<vector<int>> &adj){
	vector<int> disc(v, -1);
	vector<int> low(v, -1);
	vector<int> parent(v, -1);
	vector<pair<int, int>> bridge;
	for(int i=0; i<v; ++i){
		if(disc[i]== -1){
			dfs(i, adj, disc, low, bridge, parent);
		}
	}
	for(int i=0; i<bridge.size(); ++i){
		cout<<bridge[i].first<<"--"<<bridge[i].second<<"\n";
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

		cin>>v>>e;
		vector<vector<int>> adj(v);
		for(int i=0; i<e; ++i){
			int x, y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		//find_articulation_point
		find_bridge_tarjan(adj);  // O(v+e)

	}








    return 0;
}
