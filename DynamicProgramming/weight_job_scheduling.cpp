#include <bits/stdc++.h>
using namespace std;



//#define int long long

//const int MOD = (int)numeric_limits<int>::max();


struct Job{
    int start;
    int finish;
    int profit;
};

bool jobcomparator(Job a, Job b){
    return (a.finish < b.finish);
}

int latestnonconflict(Job arr[], int i){
    for(int j = i-1; j>=0; --j){
        if(arr[j].finish <= arr[i-1].start){
            return j;
        }
    }
    return -1;
}

// int findmaxprofit(Job arr[], int n){
//     if(n==1) return arr[n-1].profit;
//
//     int incl = arr[n-1].profit;
//     int i = latestnonconflict(arr, n);
//     if(i != -1){
//         incl += findmaxprofit(arr, i+1);
//     }
//     int excl = findmaxprofit(arr, n-1);
//     return max(incl, excl);
// }
//
// int maxprofit(Job arr[], int n){
//     sort(arr, arr+n, jobcomparator);
//     int ans = findmaxprofit(arr, n);
//     return ans;
// }

int findmaxprofitdp(Job arr[], int n){
    sort(arr, arr+n, jobcomparator);
    int table[n];
    table[0] = arr[0].profit;
    for(int i=1; i<n; ++i){
        int incl = arr[i].profit;
        int j = latestnonconflict(arr, i);
        if(j != -1){
            incl += table[j];
        }

        table[i] = max(incl, table[i-1]);
    }
    return table[n-1];

}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    // //code part
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr)/sizeof(arr[0]);
    // ( O(n*2^n) )
//    cout<<"The optimal profit "<<maxprofit(arr, n)<<"\n";

    // ( O(n*n) )
   cout<<"The optimal profit "<<findmaxprofitdp(arr, n)<<"\n";












    return 0;
}
