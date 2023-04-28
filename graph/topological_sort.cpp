
#include <bits/stdc++.h>
using namespace std;
//const int INF = (int)numeric_limits<int>::max();

bool solve(vector<vector<int>> course, vector<int> &indegree, vector<int> &ans, int n){
	queue<int> q;
	for(int i=0; i<n; ++i){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	int count = 0;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(auto a : course[cur]){
			indegree[a]--;
			if(indegree[a] == 0){
				q.push(a);
			}
		}
		ans.push_back(cur);
		count++;
	}
	if(count == n){
		return true;
	}
	return false;
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
		vector<int> indegree(n, 0);
		vector<vector<int>> course(n);
		for(int i=0; i<n; ++i){
			int x, y; cin>>x>>y;
			course[x].push_back(y);
			indegree[y]++;
		}
		vector<int> ans;
		if(solve(course, indegree, ans, n)){
			for(auto &i : ans){
				cout<<i<<" ";
			}
		}



	}









    return 0;
}
