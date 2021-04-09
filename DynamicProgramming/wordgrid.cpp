#include <bits/stdc++.h>
using namespace std;

// #define sz size()
//#define beg begin()
//#define end end()
#define mod 1000000007
#define inf 0x3f3f3f3f
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define F first
#define S second
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
typedef vector<pii> vpii;
typedef set<pii> spii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef map<string, int> msi;

bool adjacentsearch(vvc &board, string &word, int i, int j, int index){
    if(index == word.size()){
        return true;
    }
    if(i<0 || j< 0 || i>board.size()-1 || j > board[0].size()-1){
        return false;
    }
    if(board[i][j] != word[index]){
        return false;
    }
    board[i][j] = '*';
    bool searchfurther = adjacentsearch(board, word, i, j+1, index+1) ||
                  adjacentsearch(board, word, i, j-1, index+1) ||
                  adjacentsearch(board, word, i-1, j, index+1) ||
                  adjacentsearch(board, word, i+1, j, index+1);
    board[i][j] = word[index];
    return searchfurther;
}

bool exist(vvc &board, string word){
    for(int i = 0; i<board.size(); ++i){
        for(int j=0; j<board[0].size(); ++j){
            if(adjacentsearch(board, word, i, j, 0)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //code part

    //search word in grid
    vvc input = {
        { 'A','B','C','E'},
        { 'S','F','C','S' },
        { 'A','D','E','E'},
    };
    string word = "ABA";
    if(exist(input, word)){
        cout<<"The word is present"<<endl;
    }else{
        cout<<"The word is not present"<<endl;
    }





    return 0;
}
