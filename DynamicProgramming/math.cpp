
#include <bits/stdc++.h>
using namespace std;

// #define sz size()
// #define beg begin()
// #define end end()
#define mod 1000000007
#define INF 0x3f3f3f3f //1061109567
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define endl "\n"
#define eps 1e-9
#define sqr(x) ((x)*(x))
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define pb push_back
#define N 10000


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


//const int row =3; const  int col=4;

// int dfs(int sx, int sy, int count, int grid[row][col]){
//     //base condition
//     if(sx<0 || sy <0 || sx>= row  || sy>=col || grid[sx][sy] == -1){
//         return 0;
//     }
//     if(grid[sx][sy] == 2){
//         if(count== -1){
//             return 1;
//         }
//         return 0;
//     }
//
//     grid[sx][sy] = -1;
//     int total = dfs(sx+1, sy, count-1, grid) + dfs(sx-1, sy, count-1, grid) + dfs(sx, sy+1,count-1, grid)+ dfs(sx, sy-1, count-1,  grid);
//     grid[sx][sy] = 0;
//     return total;
// }
//
// int uniquepathgrid(int grid[row][col]){
//     int sx =-1; int sy =-1;
//     int count = 0;
//     for(int i=0; i<row; ++i){
//         for(int j =0; j<col; ++j){
//             if(grid[i][j] == 1){
//                 sx = i;
//                 sy =j;
//             }else if(grid[i][j] == 0){
//                 count++;
//             }
//         }
//     }
//     return dfs(sx, sy, count, grid);
// }

// // bool check(int n, int m, int obstacle[row][col]){
// //     if(n>=0 && n<row && m>=0 && m<col && !obstacle[n][m]){
// //         return true;
// //     }
// //     return false;
// // }
// // int uniquepath(int n, int m, vvi &memo, int obstacle[row][col]){
// //     if(n==row-1 || m==col-1){
// //         return 1;
// //     }
// //     if(memo[n][m] !=0){
// //         return memo[n][m];
// //     }
// //     int ans=0;
// //     if(check(n+1, m, obstacle)){
// //         ans += uniquepath(n+1, m, memo, obstacle);
// //     }
// //     if(check(n, m+1, obstacle)){
// //         ans += uniquepath(n, m+1, memo, obstacle);
// //     }
// //     memo[n][m]=ans;
// //     return ans;
// //
// // }
// int uniquepathdp(int n, int m, int memo[row][col], int obstacle[row][col]){
//     for(int i=0; i<col; ++i){
//         if(obstacle[row-1][i]){
//             memo[row-1][i]=0;
//         }
//         else memo[row-1][i]=1;
//     }
//     for(int i=0; i<row; ++i){
//         if(obstacle[i][col-1]){
//             memo[i][col-1]=0;
//         }
//         else memo[i][col-1]=1;
//     }
//     for(int i=row-2; i>=0; --i){
//         for(int j=col-2; j>=0; --j){
//             if(obstacle[i+1][j]){
//                 memo[i][j] = memo[i][j+1];
//             }
//             else if(obstacle[i][j+1]){
//                 memo[i][j] = memo[i+1][j];
//             }
//             else{
//                 memo[i][j] = memo[i+1][j] + memo[i][j+1];
//             }
//
//         }
//     }
//     return memo[0][0];
// }


//   int OneDayOneProductOnly(vvi &matrix, int day, int mask, int k){
//     //base condition
//     if(day==0){
//         if(mask==0){
//             return 0;
//         }else if((mask & (mask-1))==0){
//             return matrix[0][log2(mask)];
//         }else{
//             return INF;
//         }
//     }
//
//     int price =0;
//     price = OneDayOneProductOnly(matrix, day-1, mask, k);
//     for(int i=0; i<k; ++i){
//         if(mask&(1<<i)){
//             price = min(price, OneDayOneProductOnly(matrix, day-1, mask^(1<<i), k)+matrix[day][i]);
//         }
//     }
//     return price;
// }
// const int n = 1<<10;
// pii table[1<<10] = {mp(0,  0)};
// pii minimumrides(int mask, vi &weight, int maxweight){
//     //base condition
//     if(mask == 0){
//         return mp(1, 0);
//     }
//     int s = weight.size();
//     if(table[mask] != mp(0, 0)){
//         return table[mask];
//     }
//     auto ans = mp(s+1, 0);
//     for(int p=0; p<weight.size(); ++p){
//         if(mask&(1<<p)){
//             auto option = minimumrides(mask^(1<<p), weight, maxweight);
//             if(option.second + weight[p] <=maxweight){
//                 option.second +=weight[p];
//             }else{
//                 option.first++;
//                 option.second = weight[p];
//             }
//              ans  = min(ans, option);
//         }
//     }
//     table[mask] = ans;
//     return ans;
// }

// int minimumpathsum(vvi &matrix){
//     if(!matrix.size() || !matrix[0].size()){
//         return 0;
//     }
//     int x = matrix.size()-1;
//     int y = matrix[0].size()-1;
//     int qlen=1; int prev = INF;
//     queue<pii> q;
//     q.push(mp(x, y));
//     while(qlen){
//         for(int i=0; i<qlen; ++i){
//             x = q.front().first;
//             y = q.front().second;
//             q.pop();
//             if(x>0){
//                 matrix[y][x-1] +=min(matrix[y][x], prev);
//                 q.push(mp(x-1, y));
//             }
//             prev = matrix[y][x];
//             if(y>0 && i == qlen - 1){
//                 matrix[y-1][x] += prev;
//                 q.push(mp(x, y-1));
//             }
//         }
//         qlen = q.size();
//         prev = INF;
//     }
//     return matrix[0][0];
// }
//
// struct Node{
//     pii p;
//     int weight;
//     Node(int x, int y, int w){
//         this->p.first = x;
//         this->p.second = y;
//         this->weight =w;
//     }
// };
// struct compare{
//     bool operator()(Node &a, Node &b){
//         return a.weight > b.weight;
//     }
// };
//
// int minimumpathDijkstra(vvi &matrix){
//     int n = matrix.size();
//     int m = matrix.front().size();
//     priority_queue<Node, vector<Node>, compare> pq;
//     vpii direction = {{0,1}, {1, 0}};
//     Node nd(0, 0, matrix[0][0]);
//     pq.push(nd);
//     int distance[n][m];
//     int visited[n][m];
//     for(int i=0; i<n; ++i){
//         for(int j=0; j<m; ++j){
//             distance[i][j]= INF;
//             visited[i][j] = false;
//         }
//     }
//     distance[0][0] = matrix[0][0];
//     while(!pq.empty()){
//         if(visited[(pq.top().p).first][(pq.top().p).second]){
//             pq.pop();
//             continue;
//         }
//         Node nn = pq.top();
//         auto inx = nn.p;
//         visited[inx.first][inx.second] = true;
//         for(int i=0; i<direction.size(); ++i){
//             int row = inx.first + direction[i].first;
//             int col = inx.second + direction[i].second;
//             if(row>=0 && row<n && col>=0 && col<m && !visited[row][col] && distance[inx.first][inx.second] + matrix[row][col] < distance[row][col]){
//                  distance[row][col] = distance[inx.first][inx.second] + matrix[row][col];
//                  Node nd(row, col, distance[row][col]);
//                  pq.push(nd);
//             }
//         }
//     }
//     return distance[n-1][m-1];
// }
//
// int minimumpathsumDp(vvi &matrix, int n, int m, vvi &dp){
//     if(n<0 || m<0) return INF;
//      if(n==0 && m==0){
//         return matrix[n][m];
//     }
//     if(dp[n][m] != -1){
//         return dp[n][m];
//     }
//     int r = matrix[n][m] + min(minimumpathsumDp(matrix, n, m-1, dp), minimumpathsumDp(matrix, n-1, m, dp));
//     dp[n][m] =r;
//     return r;
// }

// int climbstairways(int n, int i, vi &memo){
//     if(i>n) return 0;
//     if(i==n){
//         return 1;
//     }
//     if(memo[i] != -1){
//         return memo[i];
//     }
//     memo[i] = climbstairways(n, i+1, memo) + climbstairways(n, i+2, memo);
//     return memo[i];
// }
//
// int mincoststair(vi &cost, vi &memo, int i){
//     if(i>=cost.size()){
//         return 0;
//     }
//     if(cost.size()==0){
//         return 0;
//     }
//     if(cost.size()==1){
//         return cost[0];
//     }
//     if(cost.size()==2){
//         return min(cost[0], cost[1]);
//     }
//     if(memo[i] != -1){
//         return memo[i];
//     }
//     int val = min(cost[i] + mincoststair(cost, memo, i+1), cost[i] + mincoststair(cost, memo, i+2));
//     memo[i] = val;
//     return val;
// }
//
// int number(int n, vi &memo){
//     if(n<=0){
//         return 0;
//     }
//     if(n==1 || n==2){
//         return 1;
//     }
//     if(memo[n] != -1){
//         return memo[n];
//     }
//     //cout<<"sushil";
//     int ways= number(n-1, memo) + number(n-2, memo) + number(n-3, memo);
//     memo[n]=ways;
//     return ways;
//
// }

// int longestpalidromesubsequence(string str, int i, int j, vvi &dp){
//     if(i==j){
//         return 1;
//     }
//     if(str[i]==str[j] && i+1==j){
//         return 2;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     if(str[i] == str[j]){
//         return dp[i][j] = longestpalidromesubsequence(str, i+1, j-1, dp) +2;
//     }
//     dp[i][j] = max(longestpalidromesubsequence(str, i+1, j, dp), longestpalidromesubsequence(str, i, j-1, dp));
//     return dp[i][j];
// }

// int matrixchainmultiplied(vi &arr, int i, int j, vvi &dp){
//     if(i==j){
//         return 0;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     dp[i][j]=INF;
//     for(int k=i; k<j; ++k){
//         dp[i][j] = min(dp[i][j], matrixchainmultiplied(arr, i, k, dp)+matrixchainmultiplied(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j]);
//     }
//     return dp[i][j];
// }

// int matrixchainmultiplieddp(vi &arr, vvi &dp){
//     int n = arr.size();
//     for(int i=1; i <n; ++i){
//         dp[i][i] = 0;
//     }
//     for(int len = 2; len<n; ++len){
//         for(int i=1; i<n-len+1; ++i){
//             int j = i+len-1;
//             dp[i][j] =INF;
//             for(int k=i; k<=j-1; ++k){
//                 int q = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[j]*arr[k];
//                 if(q<dp[i][j]){
//                     dp[i][j] = q;
//                 }
//             }
//         }
//     }
//     return dp[1][n-1];
// }

// int countPSdp(string str, int i, int j, vvi &dp){
//     if(i>j){
//         return 0;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     if( i == j){
//         return dp[i][j] = 1;
//     }
//     if(str[i] == str[j]){
//         return dp[i][j] = (countPSdp(str, i+1, j, dp)+ countPSdp(str, i, j-1, dp)+1);
//     }
//     dp[i][j] = countPSdp(str, i+1, j, dp)+ countPSdp(str, i, j-1, dp)-countPSdp(str, i+1, j-1, dp);
//     return dp[i][j];
// }

// int longestpalindromesubstring(string str, int i, int j, vvi &dp){
//     if(i>j){
//         return 0;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     if(i==j){
//         return dp[i][j] = 1;
//     }
//     if(str[i]==str[j]){
//         return dp[i][j] = max(longestpalindromesubstring(str, i+1, j-1, dp)+2, max(longestpalindromesubstring(str, i, j-1, dp), longestpalindromesubstring(str, i+1, j, dp)));
//     }
//     dp[i][j] = max(longestpalindromesubstring(str, i, j-1, dp), longestpalindromesubstring(str, i+1, j, dp));
//     return dp[i][j];
// }

// int longestpalindromesubstringdp(string str, vvb &dp){
//     int n = str.size();
//     for(int i=0; i<n; ++i){
//         dp[i][i]=true;
//     }
//     int start=0;
//     int len =2;
//     int maxlen=2;
//     for(int i=0; i<n-len+1; ++i){
//         if(str[i]==str[i+1]){
//             dp[i][i+1]=true;
//             start=i;
//             maxlen=2;
//         }
//     }
//     for(len = 3; len<=n; ++len){
//         for(int i = 0; i<n-len+1; ++i){
//             int j = i+len-1;
//             if(dp[i+1][j-1] && str[i] == str[j]){
//                 dp[i][j] = true;
//                 if(maxlen<len){
//                     maxlen = len;
//                     start = i;
//                 }
//             }
//         }
//     }
//     return maxlen;
//
// }

// int countPsubstring(string str, int i, int j, vvb& ps, vvi &dp){
//     if(i>j){
//         return 0;
//     }
//     if(dp[i][j] !=0){
//         return dp[i][j];
//     }
//
//     if(i+1==j){
//         if(str[i]==str[j]){
//             ps[i][j]=true;
//             return 1;
//         }
//     }
//     if(i==j){
//         ps[i][j] = true;
//         return 1;
//     }
//
//
//
//     if(str[i]==str[j] ){
//             dp[i][j] = (countPsubstring(str, i+1, j, ps, dp)+countPsubstring(str, i, j-1, ps, dp) -countPsubstring(str, i+1, j-1, ps, dp));
//             if(ps[i+1][j-1]){
//                 ps[i][j]=true;
//                 dp[i][j] +=1;
//             }
//             return dp[i][j];
//     }
//     return dp[i][j] = (countPsubstring(str, i+1, j, ps, dp)+countPsubstring(str, i, j-1, ps, dp)-countPsubstring(str, i+1, j-1, ps, dp));
// }
//
// int manachersalgo(string str){
//     string s;
//     string z = "*";
//     for(int i=0; i<str.size(); ++i){
//         s += z+str[i] ;
//     }
//     s = s+z;
//     int lps[s.size()];
//     int mirror=0; int r=0;
//     int c=0; int maxlen=0; int maxc=0;
//     memset(lps, 0, sizeof(lps));
//     for(int i=0; i<s.size(); ++i){
//         mirror = 2*c-i;
//         if(i<r){
//             lps[i]=min(r-i, lps[mirror]);
//         }
//         int a = i + (1+lps[i]);
//         int b = i - (1+lps[i]);
//         while(a<s.size() && b>=0 && s[a] == s[b]){
//             lps[i]++;
//             a++;
//             b--;
//         }
//         if(i+lps[i]>r){
//             c=i;
//             r=i+lps[i];
//         }
//         if(maxlen<lps[i]){
//             maxlen = lps[i];
//             maxc=i;
//         }
//     }
//     int start = (maxc-maxlen);
//     int end = maxc + maxlen-1;
//     for(int i=start; i<=end; ++i ){
//         if((s[i]!='*')){
//             cout<<s[i];
//         }
//     }
//     cout<<endl;
//     return 0;
// }

// int editdistance(string word1, string word2, int n, int m, unordered_map<string, int> &dp){
//     if(!n && !m) return 0;
//     if(!n) return m;
//     if(!m) return n;
//     string str = to_string(n)+"_"+to_string(m);
//     if(dp.count(str)){
//         return dp[str];
//     }
//
//     if(word1[n-1] == word2[m-1]){
//         dp[str] = editdistance(word1, word2, n-1, m-1, dp);
//     }else{
//         int replce = editdistance(word1, word2, n-1, m-1, dp);
//         int del = editdistance(word1, word2, n, m-1, dp);
//         int insrt = editdistance(word1, word2, n-1, m, dp);
//         dp[str] = 1 + min(replce, min(del, insrt));
//     }
//     return dp[str];
// }

// int mindelete(string word1, string word2, int i, int j, vvi &dp){
//     if(i==0 || j==0){
//         return 0;
//     }
//     if(dp[i][j] !=-1){
//         return dp[i][j];
//     }
//     if(word1[i-1]==word2[j-1]){
//         char c =word1[i-1];
//         return dp[i][j] = mindelete(word1, word2, i-1, j-1, dp)+(int)c;
//     }
//     dp[i][j] = max(mindelete(word1, word2, i-1, j, dp), mindelete(word1, word2, i, j-1, dp));
//     return dp[i][j];
// }

// int decodeways(string word, int i, vi & dp){
//     if(i>word.size()){
//         return 0;
//     }
//     if(i==word.size()){
//         return 1;
//     }
//     if(dp[i] != -1){
//         return dp[i];
//     }int sum = 0;
//     for(int j=1; j<=2; ++j){
//         string str = word.substr(i, j);
//         if(stoi(str) >=1 && stoi(str)<=26 &  word.at(0) != '0'){
//             sum += decodeways(word, i+j, dp);
//         }
//     }
//     dp[i]= sum;
//     return sum;
// }
//
// int minimumpathsum(vvi &table, int row, int col, vvi &dp){
//
//     if(row==table.size() || col >=table[row].size()){
//         return 0;
//     }
//     if(dp[row][col] != -1){
//         return dp[row][col];
//     }
//
//     dp[row][col] = table[row][col] + min(minimumpathsum(table, row+1, col, dp), minimumpathsum(table, row+1, col+1, dp));
//     return dp[row][col];
// }
//
// struct trienode{
//     trienode* child[26];
//     bool isendofword;
// };
// trienode *newNode(){
//     trienode *node = new trienode;
//     node->isendofword = false;
//     for(int i=0; i<26; ++i){
//         node->child[i]=nullptr;
//     }
//     return node;
// }
// void insrt(trienode *root, string key){
//     trienode *temp = root;
//     for(int i=0; i<key.size(); ++i){
//         int c = key[i]-'a';
//         if(!(temp->child[c])){
//             temp->child[c]=newNode();
//         }
//         temp = temp->child[c];
//     }
//     temp->isendofword = true;
// }
// bool searchword(trienode* root, string word){
//     trienode *temp = root;
//     for(int i=0; i<word.size(); ++i){
//         int c = word[i]-'a';
//         if(!(temp->child[c])){
//             return false;
//         }
//         temp = temp->child[c];
//     }
//     return (temp && temp->isendofword);
// }
//
// bool wordbreak(string word, trienode *root, int i){
//     if(i==word.size()){
//         return true;
//     }
//     for(int i=1; i<=word.size(); ++i){
//         if(searchword(root, word.substr(0, i))){
//             return wordbreak(word.substr(i+1), root, i+1);
//         }
//     }
//     return false;
// }

// void zfunc(string s, string patt){
//     patt = patt +"$";
//     s = patt + s;
//     int n = s.length();
//     vi z(n);
//     z[0]=0; int l=0; int r=0;
//     for(int i=1; i<n; ++i){
//         if(i<=r){
//             z[i]= min(z[i-l], r-l+1);
//         }else{
//             z[i]=0;
//         }
//         while(i+z[i]<n && s[z[i]] == s[i+z[i]]){
//             ++z[i];
//         }
//         if(i+z[i]-1>r){
//             l=i;
//             r=i+z[i]-1;
//         }
//     }
//     for(int i=0; i<n; ++i){
//         if(z[i]==patt.length()-1){
//             cout<<i-patt.length()<<endl;
//         }
//     }
// }

// int maxsumsubarray(vi &arr){
//     int localmax[arr.size()];
//     int maxele = -INF;
//     localmax[0]=arr[0];
//     for(int i=1; i<arr.size(); ++i){
//         localmax[i]=max(arr[i], localmax[i-1]+arr[i]);
//         maxele = max(localmax[i], maxele);
//     }
//     return maxele;
// }
//
// int maxproductofthree(vi &arr){
//     int left[arr.size()];
//     int right[arr.size()];
//     left[0]=arr[0];
//     for(int i=1; i<arr.size(); ++i){
//         left[i]=max(left[i-1], arr[i-1]);
//     }
//     right[arr.size()-1]=arr[arr.size()-1];
//     for(int i = arr.size()-2; i>=0; --i){
//         right[i]=max(right[i+1], arr[i+1]);
//     }
//     int maxprod = -INF;
//     for(int i=1; i<arr.size()-1; ++i){
//         maxprod = max(maxprod, arr[i]*left[i]*right[i]);
//
//     }
//     return maxprod;
// }

// int maxprodsubarray(vi &arr){
//     int n = arr.size();
//     int left[n];
//     left[0]=arr[0];
//     for(int i=1; i<n; ++i){
//         left[i]= arr[i]*left[i-1];
//         if(left[i]==0){
//             left[i]=arr[i];
//         }
//     }
//     int right[n];
//     right[n-1]=arr[n-1];
//     for(int i=n-2; i>=0; --i){
//         right[i]=right[i+1]*arr[i];
//         if(right[i]==0){
//             right[i]=arr[i];
//         }
//     }
//     int mx =-INF;
//     int curr=1;
//     int cmax=0; int ans =0;
//     for(int i=0; i<n; ++i){
//          curr = max(curr*arr[i], arr[i]);
//          mx = max(mx, curr);
//          cmax = max(mx, max(left[i], right[i]));
//          ans = max(ans, cmax);
//         cout<<arr[i]<<"\t\t"<<cmax<<"\t\t"<<mx<<"\t\t"<<left[i]<<"\t\t"<<right[i]<<endl;
//     }
//     ans = max(ans, mx);
//     cout<<ans<<endl;
//     return 0;
// }

// string findsubstring(string str, string patt){
//     int n = str.length();
//     int m = patt.length();
//     unordered_map<char, int> table;
//     for(int i=0; i<m; ++i){
//         table[patt[i]]++;
//     }
//     int begin=0; int end=0;
//     int counter = table.size();
//     string ans; int len = INF;
//     while(end<n){
//         char endchar = str[end];
//         if(table.find(endchar) != table.end()){
//             table[endchar]--;
//             if(table[endchar]==0){
//                 counter--;
//             }
//         }
//         end++;
//         while(counter == 0){
//             if(end-begin<len){
//                 len = end-begin;
//                 ans = str.substr(begin, len);
//             }
//             char startchar = str[begin];
//             if(table.count(startchar)==1){
//                 table[startchar]++;
//                 if(table[startchar]>0){
//                     counter++;
//                 }
//             }
//             begin++;
//         }
//     }
//     return ans;
// }

// string longestsubstringwithKdistinctchar(string str, int k){
//     int begin=0; int end=0;
//     int len=0; int counter=0;
//     string ans="";
//     unordered_map<char, int> table;
//     while(end<str.length()){
//         char endchar = str[end];
//         table[endchar]++;
//         if(table[endchar]==1){
//             counter++;
//         }
//         end++;
//         while(counter>2){
//             char startchar = str[begin];
//             if(table.count(startchar)==1){
//                 table[startchar]--;
//                 if(table[startchar]==0){
//                     counter--;
//                 }
//             }
//             begin++;
//         }
//         if(end-begin+1>len){
//             len = end-begin;
//             ans = str.substr(begin, len);
//         }
//     }
//     return ans;
// }
//
// string longestnonrepeatchar(string str){
//     int begin=0; int end =0;
//     string ans; int len=0;
//     unordered_map<char, int> seen;
//     while(end<str.size()){
//         char endchar = str[end];
//         if(seen.count(endchar)==1 && seen[endchar]>=begin){
//             begin = seen[endchar]+1;
//         }else{
//             seen[endchar]  = end;
//             end++;
//         }
//         if(end-begin+1>len){
//             len = end-begin+1;
//             ans = str.substr(begin, len);
//         }
//     }
//     return ans;
// }

// int numSubarrprodlessthanK(vi &arr){
//     int subarrays=0;
//     int k=100;
//     int begin=0; int end=0;
//     int prod=1;
//     while(end<arr.size()){
//         prod *=arr[end++];
//         while(prod>=k && begin<end){
//             prod /=arr[begin++];
//         }
//         subarrays +=end-begin;
//     }
//     return subarrays;
//}
// int robhouse(vi &house, vi & memo , int pos){
//     if(pos >= house.size()){
//         return 0;
//     }
//     if(memo[pos] != -1){
//         return memo[pos];
//     }
//     memo[pos] = max(house[pos] + robhouse(house, memo, pos+2), robhouse(house, memo, pos+1));
//     return memo[pos];
// }

// int robhouseparttwo(vi &house, vvi &memo, int pos, bool flag){
//     if(pos>=house.size()){
//         return 0;
//     }
//     else if(pos == house.size()-1 && flag){
//         return 0;
//     }
//     if(memo[pos][flag] != -1){
//         return memo[pos][flag];
//     }
//     int not_taken = robhouseparttwo(house, memo, pos+1, flag);
//     if(pos==0){
//         flag = true;
//     }
//     int taken = robhouseparttwo(house, memo, pos+2, flag)+house[pos];
//     memo[pos][flag]=max(taken, not_taken);
//     return memo[pos][flag];
// }
// int dp[100][100][100];
// int solve(vs &str, int m, int n, int pos, int sz, vpii &p){
//     if(m==0 && n== 0){
//         return 0;
//     }
//     if( pos == sz){
//         return 0;
//     }
//     if(dp[pos][m][n] != -1){
//         return dp[pos][m][n];
//     }
//     if(p[pos].first >m || p[pos].second>n){
//         return dp[pos][m][n]=solve(str, m, n, pos+1, sz, p);
//     }
//     return dp[pos][m][n] = max(1+solve(str, m-p[pos].first, n-p[pos].second, pos+1, sz, p), solve(str, m, n, pos+1, sz, p));
// }
// int findmaxform(vs &str, int m, int n){
//     int sz = str.size();
//     vpii p;
//     for(int i=0; i<sz; ++i){
//         int countzero=0; int countone=0;
//         for(int j=0; j<str[i].size(); ++j){
//             if(str[i][j]=='0'){
//                 countzero++;
//             }else{
//                 countone++;
//             }
//         }
//         p.pb({countzero, countone});
//     }
//     memset(dp, -1, sizeof(dp));
//     return solve(str, m, n, 0, sz, p);
//
// }

// int coinchange(vi &arr, int amount, int pos, vvi &memo){
//     if(amount == 0){
//         return 0;
//     }
//     if(pos == arr.size() || amount <0){
//         return INF;
//     }
//     if(memo[pos][amount]!= -1){
//         return memo[pos][amount];
//     }
//     int not_taken = coinchange(arr, amount, pos+1, memo);
//     int taken = coinchange(arr, amount-arr[pos], pos, memo)+1;
//     return memo[pos][amount] = min(not_taken, taken);
// }

// int solve(vi &days, vi &costs, int d, vb &visited, vi &memo){
//     if(d>365){
//         return 0;
//     }
//     if(memo[d] != -1){
//         return memo[d];
//     }
//     if(!visited[d]){
//         return memo[d] = solve(days, costs, d+1, visited, memo);
//     }
//     int ans  = min(costs[0]+solve(days, costs, d+1, visited, memo), min(costs[1] + solve(days, costs, d+7, visited, memo), costs[2]+solve(days, costs, d+30, visited, memo)));
//     return memo[d]=ans;
// }
//
// int mincostfortickets(vi &days, vi &costs){
//     vb visited(366, false);
//     vi memo(366, -1);
//     for(auto i : days){
//         visited[i]=true;
//     }
//     return solve(days, costs, 0, visited, memo);
// }
// int integerbreak(int n, int target, vi &memo){
//     if(target<0){
//         return 0;
//     }
//     if(target == 0){
//         return 1;
//     }
//     if(memo[target] != -1){
//         return memo[target];
//     }
//     int maxans=0; int ans;
//     for(int i=1; i<n; ++i){
//         ans = i*integerbreak(n, target-i, memo);
//         maxans = max(ans, maxans);
//     }
//     return memo[target]=maxans;
// }

// class segmentTree{
// public:
//     vi st;
//     int buildtree(vi &arr, int start, int end, int pos){
//         if(start > end ){
//             return 0;
//         }
//         if(start == end){
//             st[pos]=arr[start];
//             return st[pos];
//         }
//         int mid = start + (end-start)/2;
//         int left = buildtree(arr, start, mid, pos*2+1);
//         int right = buildtree(arr, mid+1, end, pos*2+2);
//         st[pos] = left+right;
//         return st[pos];
//     }
//     int query(int l, int r, int start, int end, int pos){
//         if(l>end || r<start){
//             return 0;
//         }
//         if(l<=start && r>=end){
//             return st[pos];
//         }
//         int mid = start + (end-start)/2;
//         int left = query(l, r, start, mid, pos*2+1);
//         int right = query(l, r, mid+1, end, pos*2+2);
//         return left+right;
//     }
//     int sumrange(int i, int j, vi &arr){
//         if(i>j){
//             return 0;
//         }
//         int sum = query(i, j, 0, arr.size()-1, 0);
//         return sum;
//     }
//     void updatenode(int i, int start, int end, int pos, int diff){
//         if( i> end || i< start ){
//             return;
//         }
//         st[pos] +=diff;
//         if(start != end){
//             int mid = start + (end-start)/2;
//             updatenode(i , start, mid, pos*2+1, diff);
//             updatenode(i, mid+1, end, pos*2+2, diff);
//         }
//     }
//     void update(int i, int val, vi &arr){
//         int diff = val - arr[i];
//         arr[i] = val;
//         updatenode(i, 0, arr.size()-1, 0, diff);
//     }
//
//     void segmenttree(vi &arr){
//         int sz = arr.size();
//         int h = ceil(log2(sz));
//         int maxsz = 2*pow(2, h)-1;
//         st.resize(maxsz, 0);
//         buildtree(arr, 0, sz-1, 0);
//     }
// };

// class fenwicktree{
// public:
//     vi fenwick;
//     //fenwick.resize(N, 0);
//     void addtofenwick(int i, int val, vi &arr){
//         while(i<=arr.size()){
//             fenwick[i]+=val;
//             i += (i&(-i));
//         }
//     }
//     void init_fenwick(vi &arr){
//         int sz = arr.size();
//         fenwick.resize(sz+1, 0);
//         for(int i=0; i<sz; ++i){
//             addtofenwick(i+1, arr[i], arr);
//         }
//     }
//     int get_sum(int l, int r){
//         int suml = fenwick[l];
//         while(l){
//             l -= (l&(-l));
//             suml +=fenwick[l];
//         }
//          r = r+1;
//         int sumr = fenwick[r];
//         while(r){
//             r -= (r&(-r));
//             sumr += fenwick[r];
//         }
//         int sum = sumr- suml;
//         return sum;
//     }
//     void update(int i, int val, vi &arr){
//         int diff = val - arr[i];
//         arr[i] = val;
//         addtofenwick(i+1, diff, arr);
//     }
// };

// int perfectnumbersum(int n, vi &memo){
//     if(n<=0){
//         return 0;
//     }
//     if(n==1){
//         return 1;
//     }
//     if(memo[n] != -1){
//         return memo[n];
//     }
//     int ans = INF;
//     for(int i=1; i*i<=n; ++i){
//         if(i*i<=n){
//             ans = min(ans, perfectnumbersum(n-i*i, memo)+1);
//         }
//     }
//     return memo[n]=ans;
// }
//
// int get(vi &arr, int i){
//     if(i == -1 || i == arr.size()){
//         return 1;
//     }
//     return arr[i];
// }
//
// int bullonburst(vi &arr, int start, int end, vvi &memo){
//     if(start>end){
//         return 0;
//     }
//     if(memo[start][end] != -1){
//         return memo[start][end];
//     }
//     int ans = -INF;
//     for(int k = start; k<=end; ++k){
//         ans = max(ans, get(arr, start-1)*get(arr, k)*get(arr, end+1)+ bullonburst(arr, start, k-1, memo)+bullonburst(arr, k+1, end, memo));
//     }
//     memo[start][end] = ans;
//     return ans;
// }

// int largestdivisiblesubarray(vi &arr){
//     int n = arr.size();
//     if(n==0){
//         return 0;
//     }
//     sort(arr.begin(), arr.end());
//     vi dp(n+1, 1);
//     int mx = 1;
//     for(int i=1; i<n; ++i){
//         for(int j=0; j<i; ++j){
//             if(arr[i]%arr[j]==0 && 1+dp[j]>dp[i]){
//                 dp[i] = dp[j]+1;
//                 if(dp[i]>mx){
//                     mx = dp[i];
//                 }
//             }
//         }
//     }
//     return mx;
// }
//
// int possiblecombination(vi &arr, int target, vi &memo){
//     if(target==0){
//         return 1;
//     }
//     if(memo[target]!= -1){
//         return memo[target];
//     }
//     int ans = 0;
//     for(int i=0; i<arr.size(); ++i){
//         if(arr[i]<=target){
//             ans +=possiblecombination(arr, target-arr[i], memo);
//         }
//     }
//     return memo[target]=ans;
// }
//
// int vert, edge; int dp[20][1<<20];
// int go(int u, int mask, vi adj[]){
//     if(mask == ((1<<vert)-1)){
//         return 1;
//     }
//     else if( u == vert-1){
//         return 0;
//     }
//     if(dp[u][mask] != -1){
//         return dp[u][mask];
//     }
//     int ans =0;
//     for(auto v : adj[u]){
//         if(mask & (1<<v)){
//             continue;
//         }
//         ans += go(v, mask | (1<<v), adj);
//     }
//     return dp[u][mask] = ans;
// }
//
// void hamiltonaianpath(){
//     cin>>vert>>edge;
//     vi adj[vert+1];
//     memset(dp, -1, sizeof(dp));
//     for(int i=0; i<edge; ++i){
//         int a, b;
//         cin>>a>>b;
//         --a; --b;
//         adj[a].pb(b);
//     }
//     cout<<go(0, 1<<0, adj)<<endl;
//
// }
//
// int dp[101][1025];
// int people[11][101];
// int solve(int shirt, int mask, int p){
//     if(mask == ((1<<p)-1)){
//         return 1;
//     }
//     if(shirt > 100){
//         return 0;
//     }
//     if(dp[shirt][mask] != -1){
//         return dp[shirt][mask];
//     }
//     int ans=0;
//     int temp=0;
//     for(int i=0; i<p; ++i){
//         if((mask & (1<<i))){
//             continue;
//         }
//         if(people[i][shirt]){
//             temp = (mask | (1<<i));
//             ans += solve(shirt+1, temp, p);
//         }
//     }
//     ans += solve(shirt+1, mask, p);
//     return dp[shirt][mask] = ans;
// }
// void tshirtAssignedtoPerson(){
//     int t; cin>>t;
//
//     while(t--){
//         int p; cin>>p;
//         //cout<<p<<endl;
//         memset(dp, -1, sizeof(dp));
//         memset(people, 0, sizeof(people));
//         string str;
//         cin.ignore();
//         for(int i=0; i<p; ++i){
//             getline(cin, str);
//             stringstream ss(str);
//             int a;
//             while(ss>>a){
//                 people[i][a]=1;
//                 //cout<<a<<" ";
//             }
//             //cout<<endl;
//         }
//         cout<<solve(1, 0, p)<<endl;
//     }
//
// }
//
// int dp[10][1025]; int matrix[10][10];
// int solve(int pos, int mask, int n){
//     if(pos == n){
//         return 0;
//     }
//     if(dp[pos][mask] != -1){
//         return dp[pos][mask];
//     }
//     int ans =INF;
//     for(int i=0; i<n; ++i){
//         if(!(mask & 1<<i)){
//             int temp = (mask | (1<<i));
//             ans = min(ans, matrix[pos][i] + solve(pos+1, temp, n));
//         }
//     }
//     return dp[pos][mask] = ans;
//
// }
// void NjobNpeople(){
//     int n; cin>>n;
//     memset(dp, -1, sizeof(dp));
//     memset(matrix, 0, sizeof(matrix));
//     cin.ignore();
//     for(int i=0; i<n; ++i){
//         string str;
//         getline(cin, str);
//         stringstream ss(str);
//         int x; int j=0;
//         while(ss>>x){
//             matrix[i][j++]=x;
//         }
//     }
//     cout<<solve(0, 0, n )<<endl;
//}


// void ActivitySelection(){
//     vector<int>s = {1, 3, 0, 5, 8, 5};
//     vector<int>f = {2, 4, 6, 7, 9, 9};
//
//     vpii ans;
//     priority_queue<pii, vpii, greater<pii>> p;
//     for(int i=0; i<s.size(); ++i){
//         p.push({f[i], s[i]});
//     }
//     auto it = p.top(); p.pop();
//     int en = it.first;
//     int st = it.second;
//     ans.pb({st, en});
//     while(!p.empty()){
//         auto itr = p.top(); p.pop();
//         if(itr.second >= en){
//             en = itr.first;
//             st = itr.second;
//             ans.pb({st, en});
//         }
//     }
//     for(auto i = ans.begin(); i != ans.end(); ++i){
//         cout<<"( "<<(*i).first<<", "<<(*i).second<<" ) "<<endl;
//     }
// }


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    //code part
    // 10^6 in 1 sec is the computation limit of this laptop
    // 10^(7, 8) is the computation limit of codeforces

    // row=7; //col=3;
    //vvi memo(row, vi(col, 0));
    // int obstacle[row][col] ={
    //     {0,0,0},
    //     {0,1,0},
    //     {0,0,0}
    // };
    // int  grid[row][col] = {
    //     {1,0,0,0},
    //     {0,0,0,0},
    //     {0,0,0,2}
    // };
    // int memo[row][col] = {0};
    //memset(memo, 0, sizeof(memo))
    //int count  = uniquepath(0, 0, memo, obstacle);
    //int count  = uniquepathdp(0, 0, memo, obstacle);
    //int count  = uniquepathgrid( grid);
    // int count  = uniquepathgrid1( grid);
    // cout<<count<<endl;

    // vvi matrix= {
    //     {6, 8, 5},
    //     {9, 2, 3},
    //     {5, 6, 9},
    //     {2, 2, 7},
    //     {8, 7, 3},
    //     {9, 5, 5},
    //     {1, 7, 1},
    //     {6, 2, 4}
    // };
    // int k = matrix[0].size();
    // int mask = (1<<k)-1;
    // int ans = OneDayOneProductOnly(matrix, matrix.size()-1, mask, k);
    // cout<<ans<<endl;

    // vi weight= { 2, 3, 3, 5, 6};
    // int mask = (1<<weight.size())-1;
    // int maxweight=10;

    // for(int i=1; i<10; ++i){
    //     table[i].first = INF;
    //     table[i].second = INF;
    // }
    // -------use of bitmasking for O(n!*n) -- > O(2^n*n) ------//
    // auto ans = minimumrides(mask , weight, maxweight);
    // cout<<ans.first<<" "<<ans.second<<endl;

    // vvi matrix = {
    //     {1, 3, 1},
    //     {1, 5, 1},
    //     {4, 2, 1}
    // };
    //int ans = minimumpathsum(matrix); // BFS approach
    //int ans = minimumpathDijkstra(matrix); // Dijkshta approach
    // vvi dp(matrix.size(), vi(matrix[0].size(), -1)); //memset(dp, -1, sizeof(dp));
    // int ans = minimumpathsumDp(matrix, matrix.size()-1, matrix[0].size()-1, dp);
    // cout<<ans<<endl;
    // int n =3; vi memo(n, -1);
    // int ans = climbstairways(n, 0, memo);
    // cout<<ans<<endl;
    // vi cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    // vi memo(cost.size(), -1);
    // int ans =min( mincoststair(cost, memo, 0), mincoststair(cost, memo, 1));
    // cout<<ans<<endl;
    // int n =25;
    // vi memo(n+1, -1);
    // int ans = number(n, memo);
    // cout<<ans<<endl;
    // string str ="geeksforgeeks";
    // string str = "abcb";
    //  vvi dp(str.size(), vi(str.size(), -1));
    // int ans = longestpalidromesubsequence(str, 0, str.size()-1, dp);
    // int ans  = countPSdp(str, 0, str.size()-1, dp);
    //  cout<<ans<<endl;
    //string str="abax";
    //vvi dp(str.size(), vi(str.size(), -1));
    //cout<<longestpalindromesubstring(str, 0, str.size()-1, dp)<<endl;
    // vvb dp(str.size(), vb(str.size(), false));
    // cout<<longestpalindromesubstringdp(str, dp)<<endl;
    //string str ="aba";
    //string str ="abbaeae";
    // vvb ps(str.size(), vb(str.size(), false));
    // vvi dp(str.size(), vi(str.size(), 0));
    // cout<<countPsubstring(str, 0, str.size()-1, ps, dp)<<endl;
    // string s ="forgeeksskeegfor";
    // cout<<manachersalgo(s)<<endl;
    // string word1 ="horse";
    // string word2 = "ros";
    // unordered_map<string, int> dp;
    // cout<<editdistance(word1, word2, word1.size(), word2.size(), dp)<<endl;
    // string word1 = "sea";int n=word1.size();
    // string word2 = "eat";int m = word2.size();
    // vvi dp(word1.size()+1, vi(word2.size()+1, -1));
    // cout<<(n+m-2*(mindelete(word1, word2, word1.size(), word2.size(), dp)))<<endl;
    //cout<<mindelete(word1, word2, word1.size(), word2.size(), dp)<<endl;
    // string word = "226";
    // vi dp(word.size()+1, -1);
    // cout<<decodeways(word, 0, dp)<<endl;

    // vi arr = {1, 2, 3, 4};
    // vvi dp(arr.size(), vi(arr.size(), -1));
    //cout<<matrixchainmultiplied(arr, 1, arr.size()-1, dp)<<endl;
    //cout<<matrixchainmultiplieddp(arr, dp)<<endl;

    // vvi table= {
    //     {2},
    //     {3, 4},
    //     {6, 5, 7},
    //     {4, 1, 8, 3}
    // };
    // vvi dp(table.size(), vi(table.size(), -1));
    // cout<<minimumpathsum(table, 0, 0, dp)<<endl;
    // string word ="catsandog";
    // vs table ={"cats", "and", "kog"};
    // trienode *root = new trienode;
    // for(int i=0; i<table.size(); ++i){
    //     insrt(root, table[i]);
    // }
    // wordbreak(word, root, 0) ? cout<<"Possible "<<endl : cout<<"Not possible"<<endl;

    // string word = "GEEKSFORGEEKS";
    // string patt = "GEEK";
    // zfunc(word, patt);

    // vi arr= {-2,1,-3,4,-1,2,1,-5,4};
    // cout<<maxsumsubarray(arr)<<endl;
    // vi arr={-2, 3, -3, -2, 5, -6, -4, 4, -7, -5};
    // cout<<maxproductofthree(arr)<<endl;
    // vi arr ={2, 3, -2, 3};
    // cout<<maxprodsubarray(arr)<<endl;

    // string str ="cbaebabacd";
    // string patt = "abc";
    //string answer = findsubstring(str, patt);
    //string answer = longestsubstringwithKdistinctchar(str, 2);
    // string answer = longestnonrepeatchar(str);
    // cout<<answer<<endl;
    // vi arr ={10, 5, 2, 6};
    // cout<<numSubarrprodlessthanK(arr)<<endl;
    // vi house={2, 2, 3, 3, 3, 4};
    // vi memo(house.size(), -1);
    // cout<<robhouse(house, memo, 0)<<endl;
    // vvi memo(house.size(), vi(2, -1));
    // cout<<robhouseparttwo(house, memo, 0, false)<<endl;

    // vs str = {"10","0001","111001","1","0"};
    // cout<<findmaxform(str, 5, 3)<<endl;
    // vi arr = {1, 2, 5};
    // int amount =11;
    // vvi memo(arr.size(), vi(amount+1, -1));
    // int ans  = coinchange(arr, amount, 0, memo);
    // if(ans == INF){
    //     cout<<"NP"<<endl;
    // }else{
    //     cout<<ans<<endl;
    // }

    // vi days = {1,2,3,4,5,6,7,8,9,10,30,31};
    // vi costs = {2, 7, 15};
    // cout<<mincostfortickets(days, costs)<<endl;
    // int n = 10;
    // vi memo(n+1, -1);
    // cout<<integerbreak(n, n, memo)<<endl;

    // vi arr = {-2, 0, 3, -5, 2, -1};
    // segmentTree seg;
    // seg.segmenttree(arr);
    // cout<<seg.sumrange(0, 2, arr)<<endl;
    // seg.update(1, 4, arr);
    // cout<<seg.sumrange(0, 2, arr)<<endl;

    // fenwicktree fen;
    // fen.init_fenwick(arr);
    // cout<<fen.get_sum(0, 2)<<endl;
    // fen.update(1, 4, arr );
    // cout<<fen.get_sum(0, 2)<<endl;
    // int n  = 13;
    // vi memo(n+1, -1);
    // cout<<perfectnumbersum(n, memo);
    // vi arr ={3, 1, 5, 8};
    // vvi memo(arr.size(), vi(arr.size(), -1));
    // cout<<bullonburst(arr, 0, arr.size()-1, memo)<<endl;
    // vi arr = {1,2,4,8, 5};
    // cout<<largestdivisiblesubarray(arr)<<endl;
    // vi arr = {1, 2, 3}; int target = 4;
    //  vi memo(target+1, -1);
    // cout<<possiblecombination(arr, target, memo)<<endl;

    //hamiltonaianpath();
    //tshirtAssignedtoPerson();
    //NjobNpeople();
    //ActivitySelection();




























	return 0;
}
