
#include <bits/stdc++.h>
using namespace std;
//const int INF = (int)numeric_limits<int>::max();

bool isbipartite(vector<vector<int>> &adj, int n, int node, vector<int> &colour){
	queue<int> q;
	q.push(node);
	colour[node]=1;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int ele : adj[cur]){
			if(colour[ele] == colour[cur]){
				return false;
			}
			if(colour[ele] == -1){
				colour[ele] = 1 - colour[cur];
				q.push(ele);
			}
		}
	}
	return true;
}

bool possible_bipartite(int n, vector<vector<int>> &dislikes){
	vector<vector<int>> adj(n+1);
	for(int i=0; i<dislikes.size(); ++i){
		adj[dislikes[i][0]].push_back(dislikes[i][1]);
		adj[dislikes[i][1]].push_back(dislikes[i][0]);
	}
	vector<int> colour(n+1, -1);
	for(int i=1; i<=n; ++i){
		if(colour[i]== -1){
			if(!isbipartite(adj, n, i, colour)){
				return false;
			}
		}
	}
	return true;
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
		vector<vector<int>> dislikes;
		for(int i=0; i<n; ++i){
			vector<int> temp;
			temp.clear();
			for(int j=0; j<2; ++j){
				int x; cin>>x;
				temp.push_back(x);
			}
			dislikes.push_back(temp);
		}
		if(possible_bipartite(n, dislikes)){
			cout<<"Bipartite graph"<<"\n";
		}else{
			cout<<"Not possible"<<"\n";
		}
		//input/output
		// 1
		// 5
		// 1 2
		// 2 3
		// 2 4
		// 3 5
		// 4 5


	}









    return 0;
}
