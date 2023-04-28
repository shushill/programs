
#include <bits/stdc++.h>
using namespace std;
//const int INF = (int)numeric_limits<int>::max();


struct edges{
	int src;
	int dest;
	int wt;
};
int v, e;
void bellmonford_algo(vector<edges> &edgelist){
	vector<int> parent(v);
	vector<int> cost_parent(v);
	vector<int> value(v, INT_MAX);
	parent[0]=-1;
	value[0]=0;
	bool updated;
	for(int i=0; i<v-1; ++i){
		updated = false;
		for(int j=0; j<e; ++j){
			int u = edgelist[j].src;
			int vv = edgelist[j].dest;
			int wtt = edgelist[j].wt;
			if(value[u] != INT_MAX && value[u]+wtt<value[vv]){
				value[vv] = value[u]+wtt;
				parent[vv]=u;
				cost_parent[vv]=value[vv];
				updated = true;
			}
		}
		if(updated == false){
			break;
		}
	}

	for(int j=0; (j<e && (updated == true)); ++j){
		int u = edgelist[j].src;
		int vv = edgelist[j].dest;
		int wtt = edgelist[j].wt;
		if(value[u] != INT_MAX && value[u]+wtt<value[vv]){
			cout<<"graph has -ve edge weight cycle"<<"\n";
			break;
		}
	}
	for(int i=1; i<v; ++i){
		//cout<<parent[i]<<" --> "<<i<<" value = "<<value[i]<<"\n";
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  Cost to reach "<<parent[i]<<"from source 0 = "<<value[i]<<"\n";
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
		vector<edges> edgelist(e);
		for(int i=0; i<e; ++i){
			int x, y , c;
			cin>>x>>y>>c;
			edgelist[i].src = x;
			edgelist[i].dest = y;
			edgelist[i].wt = c;
		}
		bellmonford_algo(edgelist);
	}








    return 0;
}
