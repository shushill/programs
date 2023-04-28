
#include <bits/stdc++.h>
using namespace std;
//const int INF = (int)numeric_limits<int>::max();

void dijkstra_algo(vector<pair<int, int>> adj[], int src, int v){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(v, INT_MAX);
	pq.push({0, src});
	dist[src]=0;
	while(!pq.empty()){
		int node = pq.top().second;
		pq.pop();
		for(auto pair_node_dist : adj[node]){
			int adj_node = pair_node_dist.first;
			int w = pair_node_dist.second;
			if( dist[node] + w < dist[adj_node]){
				dist[adj_node] = dist[node]+w;
				pq.push({dist[adj_node], adj_node});
			}
		}
	}
	for(int i=0; i<v; ++i){
		cout<<src<<"-->"<<dist[i]<<"\n";
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
		int v, e;
		cin>>v>>e;
		vector<pair<int, int>> adj[v];
		for(int i=0; i<e; ++i){
			int x, y, c;
			cin>>x>>y>>c;
			adj[x].push_back({y, c});
		//	adj[y].push_back({x, c});
		}
		dijkstra_algo(adj, 0, v);
	}









    return 0;
}
