#include <bits/stdc++.h>
using namespace std;

// #define sz size()
// #define beg begin()
// #define end end()
#define mod 1000000007
#define INF 0x3f3f3f3f
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define endl "\n"
#define eps 1e-9
#define sqr(x) ((x)*(x))
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define pb push_back
#define N 100


typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<char> vc;
typedef vector< vc > vvc;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector< vb > vvb;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef map<string, int> msi;
typedef vector<pii> vpii;
typedef set<pii> spii;
typedef set<int> si;
typedef map<string, int> msi;

// int binarySearch(int *arr, int l, int h, int key){
//     if(l>=h){
//         if(arr[l]==key){
//             return l;
//         }else{
//             return -1;
//         }
//     }
//
//     if(l<h){
//         int mid = l + (h-l)/2;
//         if(arr[mid] == key){
//             return mid;
//         }
//         if(arr[mid]<key){
//             binarySearch(arr, l, mid-1, key);
//         }
//         return binarySearch(arr, mid+1, h, key);
//     }
//     return 0;
// }

// int jumpsearch(int *arr, int n, int key){
//     int step = abs(sqrt(n));
//     int t =step;
//     int prev=0;
//     while(arr[min(step, n)-1]<key){
//         prev +=step;
//         step +=t;
//         if(prev>=n){
//             return -1;
//         }
//     }
//     while(arr[prev]<key){
//         prev++;
//         if(prev == min(step, n)){
//             return -1;
//         }
//     }
//     if(arr[prev]== key){
//         return prev;
//     }
//     return -1;
// }

// int exponentialsearch(int *arr, int n, int key){
//     if(arr[0]==0){
//         return 0;
//     }
//     int i=1;
//     while(i<n && arr[i]<=key){
//         i = i*2;
//     }
//     return binarySearch(arr, i/2, min(i, n), key);
// }

// int bsearchoptimised(int *arr, int n, int key){
//     int l =0;
//     int r = n-1;
//     while(r-l>1){
//         int mid = l + (r-l)/2;
//         if(arr[mid] >=key){
//             r = mid;
//         }else{
//             l = mid;
//         }
//     }
//     return arr[r];
// }

// bool compare(pair<int, pii> a, pair<int, pii> b){
//     if(a.second.second != b.second.second){
//         if(a.second.second > b.second.second){
//             return true;
//         }else{
//             return false;
//         }
//     }else{
//         if(a.second.first < b.second.first){
//             return true;
//         }else{
//             return false;
//         }
//     }
// }
//
// void sortbyfrequency(int *arr, int n){
//     unordered_map<int, pii> h;
//     for(int i=0; i<n; ++i){
//         if(h.find(arr[i]) != h.end()){
//             h[arr[i]].second++;
//         }else{
//             h[arr[i]] = mp(i, 1);
//         }
//     }
//     vector<pair<int, pii>> v;
//     for(auto it = h.begin(); it != h.end(); ++it){
//         v.pb(mp(it->first, it->second));
//     }
//     sort(v.begin(), v.end(), compare);
//     for(int i=0; i<v.size(); ++i){
//         int count = v[i].second.second;
//         while(count--){
//             cout<<v[i].first<<" ";
//         }
//     }
// }
//
// int maxProduct(int *arr, int n){
//     if(n<3){
//         return -1;
//     }
//     vi leftmin(n, -1);
//     vi rightmin(n, -1);
//     vi leftmax(n, -1);
//     vi rightmax(n, -1);
//     int max_product = INT_MIN;
//     int max_sum = arr[0];
//     int min_sum = arr[0];
//     for(int i=1; i<n; ++i){
//         leftmax[i] =max_sum;
//         if(arr[i]>max_sum){
//             max_sum = arr[i];
//         }
//         leftmin[i]= min_sum;
//         if(arr[i]<min_sum){
//             min_sum = arr[i];
//         }
//     }
//     max_sum = arr[n-1];
//     min_sum = arr[n-1];
//     for(int i=n-2; i>=0; --i){
//         rightmax[i]= max_sum;
//         if(arr[i]>max_sum){
//             max_sum = arr[i];
//         }
//         rightmin[i]= min_sum;
//         if(arr[i]<min_sum){
//             min_sum =arr[i];
//         }
//     }
//     for(int i=1; i<n-1; ++i){
//         int max1 = max(leftmax[i] * arr[i] * rightmax[i], leftmin[i]*arr[i]*rightmin[i]);
//         int max2 = max(leftmax[i] * arr[i] * rightmin[i], leftmin[i]*arr[i]* rightmax[i]);
//         max_product = max(max_product, max(max1, max2));
//     }
//     return max_product;
// }

// void findtriplets1(int *arr, int n){
//     bool found = false;
//     unordered_set<int> s;
//     int x;
//     for(int i=0; i<n-1; ++i){
//
//         for(int j=i+1; j<n; ++j){
//             x = -(arr[i] + arr[j]);
//             if(s.find(x)!=s.end()){
//                 cout<<x<<" "<<arr[i]<<" "<<arr[j]<<endl;
//                 found = true;
//             }else{
//                 s.insert(arr[j]);
//             }
//         }
//     }
//     if(!found ){
//         cout<<"NO triplets "<<endl;
//     }
// }
// void findtriplets(int *arr, int n){
//     bool found = false;
//     for(int i=0; i<n-1; ++i){
//         int l = i+1;
//         int r = n-1;
//         int x = arr[i];
//         while(l<r){
//             if(x+arr[l]+arr[r] == 0){
//                 cout<<x<<" "<<arr[l]<<" "<<arr[r]<<endl;
//                 l++;
//                 r--;
//                 found = true;
//             }
//             else if(x+arr[l]+arr[r] <0){
//                 l++;
//             }else{
//                 r--;
//             }
//         }
//     }
// }

// void minDiffAmongmaxmin(int *arr, int n, int k){
//     sort(arr, arr+n);
//     int res = INT_MAX;
//     for(int i=0; i<n-k+1; ++i){
//         int cursefdif = (arr[i+k-1] - arr[i]);
//         res = min(res, cursefdif);
//     }
//     cout<<res<<endl;
// }



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    //code part
    // int arr[] = { 2, 3, 4, 10, 40 };
    // int arr[] = { 2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8 };
    //  int n =  sizeof(arr) / sizeof(arr[0]);
    // int x = 11;
     //int result = binarySearch(arr, 0, n - 1, x);
     //int result = exponentialsearch(arr, n, x);
     //int result = jumpsearch(arr, n, x);
    // int result = bsearchoptimised(arr, n, x);
     // if(result != -1){
     //     cout<<"found successfully "<<result<<endl;
     // }
     //sortbyfrequency(arr, n);
     // int arr[] = { 1, 4, 3, -6, -7, 0 };
     //int arr[] = {0, -1, 2, -3, 1};
    //  int arr[] = {10, 20, 30, 100, 101, 102};
    // int n = sizeof(arr) / sizeof(arr[0]);

    //int max = maxProduct(arr, n);
    //findtriplets(arr, n);
    //minDiffAmongmaxmin(arr, n, 3);
    










	return 0;
}
