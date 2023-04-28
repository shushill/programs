
#include<bits/stdc++.h>
using namespace std;

// const int mod = 1e9+7;
// const int inf = 0x3f3f3f3f;
// const int N = 1e3+3;
//#define int long long

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

//
// vector<int> spiralmatrix(vector<vector<int>> &matrix){
//     vector<int> ans;
//     if(matrix.size()==0){
//         return ans;
//     }
//     int r = matrix.size();
//     int c = matrix[0].size();
//     vector<vector<bool>> seen(r, vector<bool>(c, false));
//     int dr[] = {0, 1, 0, -1};
//     int dc[] = {1, 0, -1, 0};
//     int rr = 0, cc = 0, di=0;
//     for(int i=0; i<r*c; ++i){
//         ans.push_back(matrix[rr][cc]);
//         seen[rr][cc]=true;
//         int c_r = rr+dr[di];
//         int c_c = cc+dc[di];
//         if(c_r>=0 && c_r<r && c_c>=0 && c_c<c && !seen[c_r][c_c]){
//             rr=c_r;
//             cc=c_c;
//         }else{
//             di=(di+1)%4;
//             rr+=dr[di];
//             cc+=dc[di];
//         }
//     }
//     return ans;
// }

// void spiralmatrix(vector<vector<int>> &matrix){
//     int i, k=0, l=0;
//     int m = matrix.size();
//     int n = matrix[0].size();
//     while(k<m && l<n){
//         for( i=l; i<n; ++i){
//             cout<<matrix[k][i]<<endl;
//         }
//         k++;
//         for(i=k; i<m; ++i){
//             cout<<matrix[i][n-1]<<endl;
//         }
//         n--;
//         if(k<m){
//             for(int i=n-1; i>=l; --i){
//                 cout<<matrix[m-1][i]<<endl;
//             }
//             m--;
//         }
//         if(l<n){
//             for(i=m-1; i>=k; --i){
//                 cout<<matrix[i][l]<<endl;
//             }
//             l++;
//         }
//     }
// }


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif

    vector<vector<int> > a{ { 1, 2, 3, 4 },
                            { 5, 6, 7, 8 },
                            { 9, 10, 11, 12 },
                            { 13, 14, 15, 16 } };

    // vector<int> ans = spiralmatrix(a);
    // for(auto &i : ans){
    //     cout<<i<<endl;
    // }
    //spiralmatrix(a);
    






    return 0;
}
