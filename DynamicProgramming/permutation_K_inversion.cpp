#include <bits/stdc++.h>
using namespace std;
//#define int long long
//const int MOD = (int)numeric_limits<int>::max();

const int m = 1000;
int dp[m][m];

int numberOfPermWithKInversion(int n, int k){
    if(n==0){
        return 0;
    }
    if(k==0){
        return 1;
    }
    if(dp[n][k] != 0){
        return dp[n][k];
    }
    int sum=0;
    for(int i=0; i<=k; ++i){
        if(i<=n-1){
            sum += numberOfPermWithKInversion(n-1, k-i);
        }
    }
    dp[n][k]=sum;
    return dp[n][k];
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    // //code part

    int N = 4;
    int K = 2;
    cout << numberOfPermWithKInversion(N, K)<<"\n";














    return 0;
}
