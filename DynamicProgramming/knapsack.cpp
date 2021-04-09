#include <bits/stdc++.h>
using namespace std;



//#define int long long

//const int MOD = (int)numeric_limits<int>::max();

// int knapSack(int W, int wt[], int val[], int n){
//     if(n==0 || W==0){
//         return 0;
//     }
//     if(wt[n] > W){
//         return knapSack(W, wt, val, n-1);
//     }
//     return max(val[n] + knapSack(W-wt[n], wt, val, n-1), knapSack(W, wt, val, n-1));
// }

// int knapSack(int w, int wt[], int val[], int n, vector<vector<int>> &dp){
//     if(n==0 || w==0){
//         return 0;
//     }
//     if(dp[n][w] != -1){
//         return -1;
//     }
//     if(wt[n-1] > w){
//         return dp[n][w] = knapSack(w, wt, val, n-1, dp);
//     }
//     int ans = max(val[n-1] + knapSack(w-wt[n-1], wt, val, n-1, dp), knapSack(w, wt, val, n-1, dp));
//     return dp[n][w] = ans;
// }

int knapSack(int W, int wt[], int val[], int n){

    // for(int i=0; i<=n; ++i){
    //     for(int w=0; w<=W; ++w){
    //         if(i==0 || w==0){
    //             dp[i][w] = 0;
    //         }
    //         else if(wt[i-1]<=w){
    //             dp[i][w] = max(val[i-1]+dp[i-1][w-wt[i-1]], dp[i-1][w]);
    //         }else{
    //             dp[i][w] = dp[i-1][w];
    //         }
    //     }
    // }
    // return dp[n][W];

    // vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    // for(int w=0; w<=W; ++w){
    //     for(int i=0; i<=n; ++i){
    //         if(i==0 || w==0){
    //             dp[i][w] = 0;
    //         }
    //         else if(wt[i-1]<=w){
    //             dp[i][w] = max(val[i-1]+dp[i-1][w-wt[i-1]], dp[i-1][w]);
    //         }else{
    //             dp[i][w] = dp[i-1][w];
    //         }
    //     }
    // }
    //  return dp[n][W];

    // vector<vector<int>> dp(W+1, vector<int>(n+1, 0));
    // for(int w=0; w<=W; ++w){
    //     for(int i=0; i<=n; ++i){
    //         if(i==0 || w==0){
    //             dp[w][i] = 0;
    //         }
    //         else if(wt[i-1]<=w){
    //             dp[w][i] = max(val[i-1]+dp[w-wt[i-1]][i-1], dp[w][i-1]);
    //         }else{
    //             dp[w][i] = dp[w][i-1];
    //         }
    //     }
    // }
    //  return dp[W][n];





}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    // //code part

    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << knapSack(W, wt, val, n);










    return 0;
}
