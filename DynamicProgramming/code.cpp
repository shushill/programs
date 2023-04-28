#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;     
const int inf = 0x3f3f3f3f;
const int N = 1e3+3;
#define int long long

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

vector<string> lettercombination(string &digits){
    vector<string> res;
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.push_back("");
    for(int i =0; i<digits.size(); ++i){
        vector<string> temp;
        string chars = charmap[digits[i] - '0'];
        for(int c = 0; c < chars.size(); ++c){
            for(int j=0; j <res.size(); ++j){
                temp.push_back(res[j] + chars[c]);
            }
        }
        res = temp;
    }
    return res;
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif

    string digits = "23";
    vector<string> res = lettercombination(digits);
    //vector<string> res = lettercombinationbacktrack(digits);
    for( auto &i : res){
        for(auto &j : i){
            cout<<j;
        }
        cout<<endl;
    }



    return 0;
}


