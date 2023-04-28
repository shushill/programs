
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


// bool binary_search(int lo, int hi, int ele, vector<int> v){
//     if(lo>hi){
//         return false;
//     }
//     int mid = lo + (hi-lo)/2;
//     if(ele == v[mid]){
//         return true;
//     }
//     else if(v[mid]<ele){
//         return binary_search(mid+1, hi, ele, v);
//     }
//     else{
//         return binary_search(lo, mid-1, ele, v );
//     }
//     return false;
// }

// bool binary_search_reverse(int lo, int hi, int ele, vector<int> v){
//     if(lo>hi){
//         return false;
//     }
//     int mid = lo + (hi-lo)/2;
//     if(ele == v[mid]){
//         return true;
//     }
//     else if(v[mid]<ele){
//         return binary_search_reverse(lo, mid-1, ele, v);
//     }
//     else{
//         return binary_search_reverse(mid+1, hi, ele, v );
//     }
//     return false;
// }
//

//
// double divisionbyzero(int a, int b){
//     if(b==0){
//         throw "Division by zero! ";
//     }
//     return (a/b);
// }


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif


    // int n; cin>>n;
    // vector<int> v(n);
    // for(auto &i : v){
    //     cin>>i;
    // }
    // //reverse(v.begin(), v.end());
    // int to_find = 12;
    // int lo = 0;
    // int hi = n-1;
    // int mid;
    // while(hi-lo>1){
    //     mid = lo+(hi-lo)/2;
    //     if(v[mid]<to_find){
    //         lo = mid+1;
    //     }else{
    //         hi = mid;
    //     }
    // }
    // if(v[lo]==to_find){
    //     cout<<lo<<endl;
    // }else if(v[hi]==to_find){
    //     cout<<hi<<endl;
    // }else{
    //     cout<<"Not found"<<endl;
    // }


    // while(lo<=hi){
    //     mid = (lo+hi)/2;
    //     if(to_find == v[mid]){
    //         cout<<"element found"<<endl;
    //         break;
    //     }
    //     else if(to_find > v[mid]){
    //         lo = mid+1;
    //     }else{
    //         hi = mid;
    //     }
    // }
    // int res = -1;
    // while(lo<=hi){
    //     mid = lo+(hi-lo)/2;
    //
    //     if(to_find == v[mid]){
    //         res = mid;   // to store index of searched element
    //         //hi = mid-1; //first occurence
    //         //lo = mid+1; // last occurence
    //         //break;
    //     }
    //     else if(to_find > v[mid]){
    //         lo = mid+1;
    //     }else{
    //         hi = mid-1;
    //     }
    // }
    // cout<<res<<endl;
    // int res = -1;
    // while(lo<=hi){
    //     mid = lo+(hi-lo)/2;
    //     int next = (mid+1)%(n);
    //     int prev = (mid+n-1)%(n);
    //
    //     if(v[prev]>v[mid]&&v[mid]<v[next]){
    //         res = mid;   // to store index of searched element
    //         break;
    //     }
    //     if(to_find > v[mid]){
    //         lo = mid+1;
    //     }else{
    //         hi = mid;
    //     }
    // }
    // cout<<res<<endl;

    // if(binary_search(lo, res-1, to_find, v)){
    //     cout<<"Found"<<endl;
    // }
    // if(binary_search_reverse(lo, hi, to_find, v)){
    //     cout<<"Found"<<endl;
    // }
    // if(binary_search(lo, hi, to_find, v)){
    //     cout<<"Found"<<endl;
    // }

    // int a =11;
    // int b =0;
    // double c;
    // try{
    //     c = divisionbyzero(a, b);
    //     cout<<c<<endl;
    // }
    // catch(const char* message){
    //     cerr<<message<<endl;
    // }
    // catch(...){
    //     cerr<<"Default error"<<endl;
    // }
    









    return 0;
}
