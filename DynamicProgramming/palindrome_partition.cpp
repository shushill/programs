#include <bits/stdc++.h>
using namespace std;
//#define int long long
//const int MOD = (int)numeric_limits<int>::max();

// const int n = 1000;
// int dp[n][n];
// int matrixchainmultiply(std::vector<int> &p, int i, int j){
//     if(i==j){
//         return 0;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     dp[i][j] = INT_MAX;
//     for(int k=i; k<j; ++k){
//         dp[i][j] = min(dp[i][j], matrixchainmultiply(p, i, k)+ matrixchainmultiply(p, k+1, j)+ p[i-1]*p[k]*p[j]);
//     }
//     return dp[i][j];
// }
//

bool ispalindrome(string str, int i, int j){
    while(i<j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int minpalparti_memo(string input, int i, int j, unordered_map<string, int> memo){
    if(i>j){
        return 0;
    }
    string ij = (to_string(i) + " " + to_string(j));
    if(memo.find(ij) != memo.end()){
        return memo[ij];
    }
    if(i==j){
        memo[ij]=0;
        return 0;
    }
    if(ispalindrome(input, i, j)){
        memo[ij]=0;
        return 0;
    }
    int minimum = INT_MAX;
    for(int k=i; k<j; ++k){
        string left = (to_string(i) + " " + to_string(k));
        string right = (to_string(k+1) + " " + to_string(j));
        int left_min, right_min;
        if(memo.find(left) != memo.end()){
            left_min = memo[left];
        }else{
            left_min = minpalparti_memo(input, i, k, memo);
        }
        if(memo.find(right) != memo.end()){
            right_min = memo[right];
        }else{
            right_min = minpalparti_memo(input, k+1, j, memo);
        }
        minimum = min(minimum, right_min+1+left_min);
    }
    memo[ij] = minimum;
    return minimum;
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    // //code part

    // vector<int> arr= {1, 2, 3, 4};
    // cout<<matrixchainmultiply(arr, 1, arr.size()-1)<<"\n";

    string input = "ababbbabbababa";
    unordered_map<string, int> memo;
    cout << minpalparti_memo(input, 0, input.length() - 1, memo) << endl;












    return 0;
}
