
#include <bits/stdc++.h>
using namespace std;
//const int INF = (int)numeric_limits<int>::max();

int v, e;

void dfs(int u, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, vector<bool> &presentInStack, stack<int> &s ){
	static int time =0;
	disc[u]=low[u]=time;
	time++;
	s.push(u);
	presentInStack[u]=true;
	for(int v : adj[u]){
		if(disc[v]== -1){
			dfs(v, adj, disc, low, presentInStack, s);
			low[u] = min(low[u], low[v]);
		}
		else if(presentInStack[v]){
			low[u] = min(low[u], disc[v]);
		}
	}
	if(low[u] == disc[u]){
		cout<<"\nSCC is: ";
		while(s.top() != u){
			cout<<s.top()<<" ";
			presentInStack[s.top()]=false;
			s.pop();
		}
		cout<<s.top()<<" ";
		presentInStack[s.top()]=false;
		s.pop();
	}
}

void find_SCC(vector<vector<int>> &adj){
	vector<int> disc(v, -1);
	vector<int> low(v, -1);
	vector<bool> presentInStack(v, false);
	stack<int> s;
	for(int i=0; i<v; ++i){
		if(disc[i]== -1){
			dfs(i, adj, disc, low, presentInStack, s);
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
		}
		//find_strongly_connected_component
		find_SCC(adj);  // O(v+e)

	}








    return 0;
}
