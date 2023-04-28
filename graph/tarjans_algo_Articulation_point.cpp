
#include <bits/stdc++.h>
using namespace std;
//const int INF = (int)numeric_limits<int>::max();

int v, e;

void dfs(int u, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, vector<bool> &articulation_point, vector<int> &parent ){
	static int time =0;
	disc[u]=low[u]=time;
	time++;
	int children = 0;
	for(int v : adj[u]){
		if(disc[v]== -1){
			children +=1;
			parent[v]=u;
			dfs(v, adj, disc, low, articulation_point, parent);
			low[u] = min(low[u], low[v]);

			if(parent[u] == -1 && children >1){
				articulation_point[u]=true;
			}
			if(parent[u]  != -1 && low[v] >= disc[u]){
				articulation_point[u] = true;
			}
		}
		else if(v != parent[u]){
			low[u] = min(low[u], disc[v]);
		}
	}

}

void find_AP_tarjan(vector<vector<int>> &adj){
	vector<int> disc(v, -1);
	vector<int> low(v, -1);
	vector<int> parent(v, -1);
	vector<bool> articulation_point(v, false);
	for(int i=0; i<v; ++i){
		if(disc[i]== -1){
			dfs(i, adj, disc, low, articulation_point, parent);
		}
	}
	for(int i=0; i<v; ++i){
		if(articulation_point[i] == true){
			cout<<i<<" ";
		}
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
		find_AP_tarjan(adj);  // O(v+e)

	}








    return 0;
}
