
#include <bits/stdc++.h>
using namespace std;
//const int INF = (int)numeric_limits<int>::max();

void solve(vector<pair<int, int>> flights[], int &fare, int src, int dest, int costto, int k, vector<bool> &visited){
	if(k<-1){
		return;
	}
	if(src == dest){
		fare = min(fare, costto);
		return;
	}
	visited[src]= true;
	for(int i=0; i<flights[src].size(); ++i){
		if(!visited[flights[src][i].first] && costto+flights[src][i].second<=fare){
			solve(flights, fare, flights[src][i].first, dest, costto+flights[src][i].second, k-1, visited);
		}
	}
	visited[src]=false;
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
		vector<pair<int, int>> flights[v];
		for(int i=0; i<e; ++i){
			int x, y, c;
			cin>>x>>y>>c;
			flights[x].push_back({y, c});
		}
		vector<bool> visited(v, false);
		int fare = INT_MAX;
		int k = 3;int src = 0; int dest=4;
		solve(flights, fare, src, dest, 0,  k, visited);
		if(fare == INT_MAX) cout<<"Flight not possible"<<"\n";
		else cout<<"Flight fare "<<fare<<"\n";
		// 1
		// 5 6
		// 0 3 300
		// 0 1 100
		// 3 2 10
		// 4 1 100
		// 2 4 10
		// 1 3 100

	}









    return 0;
}
