
#include <bits/stdc++.h>
using namespace std;
//const int INF = (int)numeric_limits<int>::max();

int primsalgo(vector<pair<int, int>> adj[], int src, int v){
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, src});
		vector<bool> visited(v, false);
		int mst_cost=0;
		while(!pq.empty()){
			pair<int, int> p;
			p = pq.top(); pq.pop();
			int node = p.second;
			int cost = p.first;
			if(!visited[node]){
				mst_cost += cost;
				visited[node]=true;
			}
			for(auto pair_cost_node : adj[node]){
				int adj_node = pair_cost_node.first;
				int adj_cost = pair_cost_node.second;
				if(!visited[adj_node]){
					pq.push({adj_cost, adj_node});
				}
			}
		}
		return mst_cost;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int t; cin>>t;
	while(t--){
		int v, e;
		cin>>v>>e;
		vector<pair<int, int>> adj[v];
		for(int i=0; i<e; ++i){
			int x, y, c;
			cin>>x>>y>>c;
			adj[x].push_back({y, c});
			adj[y].push_back({x, c});
		}
		cout<<primsalgo(adj, 0, v)<<"\n";
	}









    return 0;
}
