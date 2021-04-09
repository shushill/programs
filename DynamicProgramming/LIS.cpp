#include <bits/stdc++.h>
using namespace std;
//#define int long long
//const int MOD = (int)numeric_limits<int>::max();



// int ans =1;
// int lis(int arr[], int n){
//
//     if(n==1){
//         return 1;
//     }
//     int max_end =1;
//     for(int i=1; i<n; ++i){
//         int res = lis(arr, i);
//         if(arr[i-1] < arr[n-1] && res+1 > max_end){
//             max_end = res+1;
//         }
//     }
//     if(max_end>ans){
//         ans = max_end;
//     }
//     return max_end;
//
// }

// int lisdp(int arr[], int n){
//     int dp[n];
//     dp[0]=1;
//     for(int i=1; i<n; ++i){
//         dp[i]=1;
//         for(int j=0; j<i; ++j){
//             if(arr[j]<arr[i] && dp[j]+1 > dp[i]){
//                 dp[i] = dp[j]+1;
//             }
//         }
//     }
//     return *max_element(dp, dp+n);
// }

void SelectActivities(vector<int> &s, vector<int> &f){
    vector<pair<int, int>> ans;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i=0; i<s.size(); ++i){
        pq.push({f[i], s[i]});
    }
    auto it = pq.top();
    int start = it.second;
    int end = it.first;
    pq.pop();
    ans.push_back({start, end});
    while(!pq.empty()){
        auto itr = pq.top(); pq.pop();
        if(itr.second >= end ){
            start = itr.second;
            end = itr.first;
            ans.push_back({start, end});
        }
    }
    for(auto &i : ans){
        cout<<"("<<i.first<<", "<<i.second<<") "<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    // //code part




    // int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    // int n = sizeof(arr)/sizeof(arr[0]);
//    cout<<lis(arr, n)<<"\n";
    //cout<<lisdp(arr, n)<<"\n";

    vector<int>s = {1, 3, 0, 5, 8, 5};
    vector<int>f = {2, 4, 6, 7, 9, 9};
    SelectActivities(s,f);  // O( nlogn )














    return 0;
}
