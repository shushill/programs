
#include <bits/stdc++.h>
using namespace std;
//const int INF = (int)numeric_limits<int>::max();

int v, e;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int node){
	visited[node]=true;
	for(auto i : adj[node]){
		if(!visited[i]){
			dfs(adj, visited, i);
		}

	}
}

bool connected_graph(vector<vector<int>> &adj){
	vector<bool> visited(v+1, false);
	int node = -1;
	for(int i=0; i<v; ++i){
		if(adj[i].size()>0){
			node=i;
			break;
		}
	}
	if(node == -1) return true;
	dfs(adj, visited,  node);
	for(int i=0 ; i<v; ++i){
		if(visited[i]==false && adj[i].size() >0){
			return false;
		}
	}
	return true;
}

int find_euler(vector<vector<int>> &adj){
	if(!connected_graph(adj)){
		return 0;
	}
	int odd = 0;
	for(int i=0; i<v; ++i){
		if(adj[i].size() & 1){
			odd++;
		}
	}
	if(odd > 2){
		return 0;   // non_eluerian graph
	}
	if(odd == 0){
		return 2;   // eulerean_graph
	}else{
		return 1;   // semi-eulerian_graph
	}
}

void find_euler_graph(vector<vector<int>> &adj){
	int ret = find_euler(adj);
	if(ret == 0){
		cout<<"Graph is non euler graph"<<"\n";
	}
	if(ret == 1){
		cout<<"Graph is Semi euler graph"<<"\n";
	}
	if(ret  == 2){
		cout<<"Graph is euler graph"<<"\n";
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
		find_euler_graph(adj);

	}








    return 0;
}
