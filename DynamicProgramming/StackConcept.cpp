
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
#define N 1000000


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


// void nearestGreaterElementToRight(int *arr, int n){
//     vi v;
//     stack<int> s;
//     for(int i=n-1; i>=0; --i){
//         if(s.empty()){
//             v.pb(-1);
//         }else if(!s.empty() && s.top()>arr[i]){
//             v.pb(s.top());
//         }else if(!s.empty() && s.top()<=arr[i]){
//             while(!s.empty() && s.top()<=arr[i]){
//                 s.pop();
//             }
//             if(s.empty()){
//                 v.pb(-1);
//             }else{
//                 v.pb(s.top());
//             }
//         }
//         s.push(arr[i]);
//     }
//     reverse(v.begin(), v.end());
//     for(auto i: v){
//         cout<<i<<endl;
//     }
// }
//
// void nearestGreaterElementToLeft(int *arr, int n){
//     vi v;
//     stack<int> s;
//     for(int i=0; i<n; ++i){
//         if(s.empty()){
//             v.pb(-1);
//         }else if(!s.empty() && s.top()>arr[i]){
//             v.pb(s.top());
//         }else if(!s.empty() && s.top()<=arr[i]){
//             while(!s.empty() && s.top()<=arr[i]){
//                 s.pop();
//             }
//             if(s.empty()){
//                 v.pb(-1);
//             }else{
//                 v.pb(s.top());
//             }
//         }
//         s.push(arr[i]);
//     }
//     for(auto i: v){
//         cout<<i<<endl;
//     }
// }

// void nearestSmallerToLeft(int *arr, int n){
//         vi v;
//         stack<int> s;
//         for(int i=0; i<n; ++i){
//             if(s.empty()){
//                 v.pb(-1);
//             }else if(!s.empty() && s.top()<arr[i]){
//                 v.pb(s.top());
//             }else if(!s.empty() && s.top()>=arr[i]){
//                 while(!s.empty() && s.top()>=arr[i]){
//                     s.pop();
//                 }
//                 if(s.empty()){
//                     v.pb(-1);
//                 }else{
//                     v.pb(s.top());
//                 }
//             }
//             s.push(arr[i]);
//         }
//         for(auto i: v){
//             cout<<i<<endl;
//         }
// }

// void nearestSmallerToRight(int *arr, int n){
//     vi v;
//       stack<int> s;
//       for(int i=n-1; i>=0; --i){
//           if(s.empty()){
//               v.pb(-1);
//           }else if(!s.empty() && s.top()<arr[i]){
//               v.pb(s.top());
//           }else if(!s.empty() && s.top()>=arr[i]){
//               while(!s.empty() && s.top()>=arr[i]){
//                   s.pop();
//               }
//               if(s.empty()){
//                   v.pb(-1);
//               }else{
//                   v.pb(s.top());
//               }
//           }
//           s.push(arr[i]);
//       }
//       reverse(v.begin(), v.end());
//       for(auto i: v){
//           cout<<i<<" ";
//       }
// }
//
// void stockSpanProblem(int *arr, int n){
//     //nearestGreaterElementToLeft
//        vi v;
//        stack<pii> s;
//        for(int i=0; i<n; ++i){
//            if(s.empty()){
//                v.pb(-1);
//            }else if(!s.empty() && s.top().first>arr[i]){
//                v.pb(s.top().second);
//            }else if(!s.empty() && s.top().first<=arr[i]){
//                while(!s.empty() && s.top().first<=arr[i]){
//                    s.pop();
//                }
//                if(s.empty()){
//                    v.pb(-1);
//                }else{
//                    v.pb(s.top().second);
//                }
//            }
//            s.push({arr[i], i});
//        }
//        for(int i=0; i<n; ++i){
//            v[i]=i-v[i];
//        }
//        for(auto i: v){
//            cout<<i<<endl;
//        }
// }
// //
// int maximumAreaHistogram(int *arr, int n){
//     //nearestSmallerToLeft
//     //nearestSmallerToRight
//     //width*arrayelement
//
//     vi left; stack<pii> s; int pseudoindex=-1;
//     for(int i=0; i<n; ++i){
//         if(s.empty()){
//             left.pb(pseudoindex);
//         }else if(!s.empty() && s.top().first < arr[i]){
//             left.pb(s.top().second);
//         }else if(!s.empty() && s.top().first >= arr[i]){
//             while(!s.empty() && s.top().first>=arr[i]){
//                 s.pop();
//             }
//             if(s.empty()){
//                 left.pb(pseudoindex);
//             }else{
//                 left.pb(s.top().second);
//             }
//         }
//         s.push({arr[i], i});
//     }
//     while(!s.empty()){
//         s.pop();
//     }
//     vi right;
//     for(int i=n-1; i>=0; --i){
//         if(s.empty()){
//             right.pb(n);
//         }else if(!s.empty() && s.top().first < arr[i]){
//             right.pb(s.top().second);
//         }else if(!s.empty() && s.top().first >= arr[i]){
//             while(!s.empty() && s.top().first>=arr[i]){
//                 s.pop();
//             }
//             if(s.empty()){
//                 right.pb(pseudoindex);
//             }else{
//                 right.pb(s.top().second);
//             }
//         }
//         s.push({arr[i], i});
//     }
//     reverse(right.begin(), right.end());
//     vi width(n); vi area(n); int maxarea=-1;
//     for(int i=0; i<n; ++i){
//         width[i] = right[i] - left[i]  -1;
//         //cout<<right[i]<<" "<<left[i]<<" "<<width[i]<<endl;
//         area[i] = width[i] * arr[i];
//         maxarea = max(maxarea, area[i]);
//     }
//     //cout<<"MAH = "<<maxarea<<endl;
//     return maxarea;
// }
// const int n=4;
// void maximumAreaRectangle(int matrix[n][n]){
//     int arr[n]={0};
//     for(int i=0; i<n; ++i){
//         arr[i]=matrix[0][i];
//     }
//     int maxarea = maximumAreaHistogram(arr, n);
//     for(int i=1; i<n; ++i){
//         for(int j=0; j<n; ++j){
//             if(matrix[i][j]==0){
//                 arr[j] = 0;
//             }else{
//                 arr[j]=arr[j]+1;
//
//             }
//             //cout<<arr[j]<<" ";
//         }
//         //cout<<endl;
//          maxarea = max(maxarea, maximumAreaHistogram(arr, n));
//         // cout<<maxarea<<endl;
//     }
//     cout<<"Maximum Area Rectangle = "<<maxarea<<endl;
// }

//void useOfStack(){
    //int arr[] = {11, 9, 21, 3};
    //int arr[] = {1, 3, 2, 4};
    // int arr[] = {4, 5, 2, 10, 8};
    // int n = sizeof(arr)/sizeof(arr[0]);
    //nearestGreaterElementToRight(arr, n); // O(N)
    //nearestGreaterElementToLeft(arr, n);
    //nearestSmallerToLeft(arr, n);
    //nearestSmallerToRight(arr, n);
    //--------------------------------//
    // int price[] = { 10, 4, 5, 90, 120, 80 };
    // int n = sizeof(price) / sizeof(price[0]);
    // stockSpanProblem(price, n); //O(N)

    // int arr[] = {2, 3, 3, 2};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // maximumAreaHistogram(arr, n);

    // int matrix[n][n] = {
    //     {0, 1, 1, 0},
    //     {1, 1, 1, 1},
    //     {1, 1, 1, 1},
    //     {1, 1, 0, 0}
    // };
    // maximumAreaRectangle(matrix);
//}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    //code part
    // 10^6 in 1 sec is the computation limit of this laptop
    // 10^(7, 8) is the computation limit of codeforces

    // Stack Conceptual problem

    //useOfStack();













	return 0;
}
