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
#define N 10


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

// void dfs(int n, int m, bool visited[N][N], int adj[N][N], int row, int col){
//     visited[n][m]=true;
//     if(n+1<row && adj[n][m]>=adj[n+1][m] && !visited[n+1][m]){
//         dfs(n+1, m, visited, adj, row, col);
//     }
//     if(n-1>=0 && adj[n][m]>=adj[n-1][m] && !visited[n-1][m]){
//         dfs(n-1, m, visited, adj, row, col);
//     }
//     if(m+1<col && adj[n][m]>=adj[n][m+1] && !visited[n][m+1]){
//         dfs(n, m+1, visited, adj, row, col);
//     }
//     if(m-1>=0 && adj[n][m]>=adj[n][m-1] && !visited[n][m-1]){
//         dfs(n, m-1, visited, adj, row, col);
//     }
// }
//
//
// void printMinSources(int adj[N][N], int n, int m){
//     vector<pair<long int, pii>> v;
//     for(int i=0; i<n; ++i){
//         for(int j=0; j<m; ++j){
//             v.pb(mp(adj[i][j], mp(i, j)));
//         }
//     }
//     sort(v.begin(), v.end());
//     bool visited[N][N];
//     memset(visited, false, sizeof(visited));
//     int i;
//     for(i = v.size()-1; i>=0; --i){
//         if(!visited[v[i].second.first][v[i].second.second]){
//             cout<<v[i].second.first<<" "<<v[i].second.second<<endl;
//             dfs(v[i].second.first, v[i].second.second, visited, adj, n, m);
//         }
//     }
// }

// struct graph{
//     int V;
//     vi *adj;
// };
// graph* creategraph(int V){
//     graph *g = new graph;
//     g->V = V;
//     g->adj = new vi[V];
//     return g;
// }
// void addegde(graph *g, int src, int dest){
//     g->adj[src].pb(dest);
//     g->adj[dest].pb(src);
// }
// void sieveeratos(vi &pset){
//     int i;
//     int n = 9999;
//     bool prime[n+1];
//     memset(prime, false, sizeof(prime));
//     for(i = 2; i*i<=n; ++i){
//         if(prime[i]) continue;
//         for(int x = i*i; x<=n; x+=i){
//             prime[x] = true;
//         }
//     }
//     for(i=1000; i<=n; ++i){
//         if(prime[i]==false){
//             pset.pb(i);
//         }
//     }
// }
//
// bool comparenum(int num1, int num2){
//     string s1 = to_string(num1);
//     string s2 = to_string(num2);
//     int c=0;
//     for(int i=0; i<(int)s1.size(); ++i){
//         if(s1[i] !=s2[i]){
//             c++;
//         }
//     }
//     if(c==1){
//         return true;
//     }else{
//         return false;
//     }
// }
//
// int bfs(graph *g, int a, int b){
//     vi visited(g->V, 0);
//     queue<int> q;
//     q.push(a);
//     visited[a]=0;
//     int i;
//     while(!q.empty()){
//         i = q.front(); q.pop();
//         for(auto it = g->adj[i].begin(); it != g->adj[i].end(); ++it){
//             if(!visited[*it]){
//                 q.push(*it);
//                 visited[*it] = visited[i] +1;
//             }
//             if(*it == b){
//                 return visited[*it];
//             }
//         }
//     }
//     return -1;
// }
//
// int shortestpath(int num1, int num2){
//     vi pset;
//     sieveeratos(pset);
//     graph *g = creategraph(pset.size());
//     int i, j;
//     for( i=0; i<pset.size(); ++i){
//         for(j=i+1; j<pset.size(); ++j){
//             if(comparenum(pset[i], pset[j])){
//                 addegde(g,i,j);
//             }
//         }
//     }
//     int x, y;
//     for(int i=0; i<pset.size(); ++i){
//         if(pset[i]==num1){
//             x =i;
//         }
//         if(pset[i]==num2){
//             y=i;
//         }
//     }
//     return bfs(g, x, y);
//
// }

// int pour(int fromJug, int toJug, int d){
//     int from = fromJug;
//     int to = 0;
//     int step =1;
//     while(from !=d && to !=d){
//         int temp = min(from, toJug-to);
//         to +=temp;
//         from -=temp;
//         step++;
//         if(from==d || to == d){
//             break;
//         }
//         if(from== 0){
//             from = fromJug;
//             step++;
//         }
//         if(to==toJug){
//             to=0;
//             step++;
//         }
//     }
//     return step;
// }
//
// void waterjugproblem(int n, int m, int d){
//     if(m>n){
//         swap(m,n);
//     }
//     if(d>n){
//         cout<<"not possible"<<endl;
//         return;
//     }
//     if(d % gcd(n, m) !=0){
//         cout<<"No answer"<<endl;
//         return;
//     }
//     int ans = min(pour(n, m, d), pour(m, n, d));
//     cout<<ans<<endl;
//     return;
//
// }
//
// void dfs(int i, int ans[], vi g[]){
//     ans[i]=1;
//     for(int k=0; k<g[i].size(); ++k){
//         if(!ans[g[i][k]]){
//             dfs(g[i][k], ans, g);
//         }
//     }
// }
//
// void printBinaryPalindrome(int n, int k){
//     int ans[n] ={0};
//     int arr[n];
//     for(int i=0; i<n; ++i){
//         arr[i]=i%k;
//     }
//     vi g[k];
//     for(int i=0; i<n/2; ++i){
//         g[arr[i]].pb(arr[n-i-1]);
//         g[arr[n-i-1]].pb(arr[i]);
//     }
//     dfs(0, ans, g);
//     for(int i=0; i<n; ++i){
//         cout<<ans[arr[i]];
//     }
// }
//
//
// bool isPossible(int m, int n, int k, int r, vi x, vi y){
//     int rect[m][n] = {0};
//     for(int i=0; i<m; ++i){
//         for(int j=0; j<n; ++j){
//             for(int p=0; p<k; ++p){
//                 if(sqrt(pow((x[p]-1-i), 2) + pow((y[p]-1-j), 2))<=r){
//                     rect[i][j]=-1;
//                 }
//             }
//         }
//     }
//     if(rect[0][0]==-1){
//         return false;
//     }
//     queue<pii> q;
//     rect[0][0]=1;
//     q.push(mp(0,0));
//     while(!q.empty()){
//         pii pq = q.front(); q.pop();
//         int elex = pq.first;
//         int eley = pq.second;
//         if((elex>0) && (eley>0) && (rect[elex-1][eley-1]==0)){
//             rect[elex-1][eley-1]=1;
//             q.push(mp(elex-1, eley-1));
//         }
//         if((elex>0) && (rect[elex-1][eley]==0)){
//             rect[elex-1][eley]=1;
//             q.push(mp(elex-1, eley));
//         }
//         if((elex>0)&& (eley+1<n) && rect[elex-1][elex+1]==0){
//             rect[elex-1][elex+1]=1;
//             q.push(mp(elex-1, eley+1));
//         }
//         if((eley<n)&& rect[elex][eley+1]==0){
//             rect[elex][eley+1]=1;
//             q.push(mp(elex, eley+1));
//         }
//         if((eley-1>=0) && rect[elex][eley-1]==0){
//             rect[elex][eley-1]=1;
//             q.push(mp(elex, eley-1));
//         }
//         if((elex+1<m)&& (eley-1<n)&& rect[elex+1][eley-1]==0){
//             rect[elex+1][eley-1]=1;
//             q.push(mp(elex+1, eley-1));
//         }
//         if((elex+1<m)&& rect[elex+1][eley]==0){
//             rect[elex+1][eley] =1;
//             q.push(mp(elex+1, eley));
//         }
//         if((elex+1<m)&& (eley+1<n) && rect[elex+1][eley+1]==0){
//             rect[elex+1][eley+1]=1;
//             q.push(mp(elex+1, eley+1));
//         }
//     }
//     return (rect[m-1][n-1]==1);
// }
//
// int buildtree(int arr[N], int n, vi adj[N]){
//     int rootindex=0;
//     for(int i=0; i<n; ++i){
//         if(arr[i]==-1){
//             rootindex = i;
//         }else{
//             adj[i].pb(arr[i]);
//             adj[arr[i]].pb(i);
//         }
//     }
//     return rootindex;
// }
//
// int bfsheight(int rootindex, vi adj[N]){
//     mii visited;
//     queue<pii> q;
//     int maxlevel=0;
//     q.push(mp(rootindex, 0));
//     pii p;
//     while(!q.empty()){
//         p = q.front(); q.pop();
//         maxlevel = max(maxlevel, p.second);
//         visited[p.first]=1;
//         for(int i=0; i<adj[p.first].size(); ++i){
//             if(!visited[adj[p.first][i]]){
//                 q.push(mp(adj[p.first][i], p.second+1));
//             }
//         }
//     }
//     return maxlevel;
// }
//
// void findheightofTree(){
//     int parent[] = { -1, 0, 0, 0, 3, 1, 1, 2 };
//     int n = sizeof(parent) / sizeof(parent[0]);
//     vi adj[N];
//     int rootindex = buildtree(parent, n, adj);
//     int ma = bfsheight(rootindex, adj);
//     cout<<"Height = "<<ma<<endl;
// }
// const int V=4;
// bool issolvable(int graph[V][V], int colour[], int c, int v){
//     for(int i=0; i<V; ++i){
//         if(graph[v][i] && c == colour[i]){
//             return false;
//         }
//     }
//     return true;
// }
//
// bool colourUtil(int graph[V][V], int colour[], int v, int m){
//     if(v==V){
//         return true;
//     }
//     for(int c=1; c<=m; ++c){
//         if(issolvable(graph, colour, c, v)){
//             colour[v]=c;
//             if(colourUtil(graph, colour, v+1, m)==true){
//                 return true;
//             }
//             colour[v]=0;
//         }
//     }
//     return false;
// }
//
// void mcolouringBacktrack(int graph[V][V]){
//
//     int m=3;
//     int colour[V];
//     for(int i=0; i<V; ++i){
//         colour[i]=0;
//     }
//     if(colourUtil(graph, colour, 0, m)){
//         cout<<"Possible"<<endl;
//     }else{
//         cout<<"Not possible solution"<<endl;
//     }
//     cout<<"colours of vertices are "<<endl;
//     for(int i=0; i<V; ++i){
//         cout<<colour[i]<<" ";
//     }
//     cout<<endl;
// }

// const int V=5;
// bool issafe(int *path, int graph[V][V], int v, int pos){
//     if(graph[path[pos-1]][v]==0){
//         return false;
//     }
//     for(int i=0; i<pos; ++i){
//         if(path[i]==v){
//             return false;
//         }
//     }
//     return true;
// }
// bool hamcycleUtil(int *path, int graph[V][V], int pos){
//     if(pos == V){
//         if(graph[path[pos-1]][path[0]]==1){
//             return true;
//         }else{
//             return false;
//         }
//     }
//     for(int v=1; v<V; ++v){
//         if(issafe(path, graph, v, pos)){
//             path[pos]=v;
//             if(hamcycleUtil(path, graph, pos+1)==true){
//                 return true;
//             }
//             path[pos]=-1;
//         }
//     }
//     return false;
// }
//
// void hamcycle(int graph[V][V]){
//     int *path = new int[V];
//     for(int i=0; i <V; ++i){
//         path[i]=-1;
//     }
//     path[0]=0;
//     if(hamcycleUtil(path, graph, 1)){
//         cout<<"possible path is "<<endl;
//         for(int i=0; i<V; ++i){
//             cout<<path[i]<<" ";
//         }
//         cout<<endl;
//     }else{
//         cout<<"Not possible"<<endl;
//     }
//     return;
// }

// const int V=9;
//
// bool findunassignplace(int grid[V][V], int &row, int &col){
//     for(row=0; row<V; ++row){
//         for(col=0; col<V; ++col){
//             if(grid[row][col]==0){
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// bool isrow(int grid[V][V], int row, int num){
//     for(int col =0; col <V; ++col){
//         if(grid[row][col]==num){
//             return true;
//         }
//     }
//     return false;
// }
// bool iscol(int grid[V][V], int col, int num){
//     for(int row =0; row <V; ++row){
//         if(grid[row][col]==num){
//             return true;
//         }
//     }
//     return false;
// }
//
// bool inbox(int grid[V][V], int srow, int scol, int num){
//     for(int row=0; row<3; ++row){
//         for(int col=0; col<3; ++col){
//             if(grid[srow+row][scol+col]==num){
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// bool issafe(int grid[V][V], int row, int col, int num){
//     if(!isrow(grid, row, num) && !iscol(grid, col, num) && !inbox(grid, row-row%3, col-col%3, num) && grid[row][col]==0){
//         return true;
//     }
//     return false;
// }
//
// bool sodukuUtil(int grid[V][V]){
//     int row, col;
//     if(!findunassignplace(grid, row, col)){
//         return true;
//     }
//     for(int num =1; num <=9; ++num){
//         if(issafe(grid, row, col, num)){
//             grid[row][col]=num;
//             if(sodukuUtil(grid)){
//                 return true;
//             }
//             grid[row][col]=0;
//         }
//     }
//     return false;
// }
//
// void soduku(int grid[V][V]){
//     if(sodukuUtil(grid)){
//         cout<<"solved "<<endl;
//         for(int i=0; i<V; ++i){
//             for(int j=0; j<V; ++j){
//                 cout<<grid[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//     }else{
//         cout<<"Not possibel"<<endl;
//     }
// }
//
// const int n=4;
// bool inrow(char board[n][n], int row, int c){
//     for(int col=0; col<row; ++col){
//         if(board[row][col]=='Q'){
//             return true;
//         }
//     }
//     return false;
// }
// bool incol(char board[n][n], int r, int col){
//     for(int row=0; row<r; ++row){
//         if(board[row][col]=='Q'){
//             return true;
//         }
//     }
//     return false;
// }
// bool indiagnal(char board[n][n], int row, int col){
//      for(int i=0; i<n; ++i){
//         for(int j=0; j<n; ++j){
//             if(abs(row-i)==abs(col-j)&& board[i][j]=='Q'){
//                 return true;
//             }
//         }
//      }
//      return false;
//
// }
//
// bool issafe(char board[n][n], int row, int col){
//     if(!inrow(board, row,  col) && !incol(board, row, col) && !indiagnal(board, row, col)){
//         return true;
//     }
//     return false;
// }
//
// bool NQueenUtil(char board[n][n], int k){
//     if(k==n){
//         return true;
//     }
//     for(int i=0; i<n; ++i){
//         if(issafe(board, k, i)){
//             board[k][i]='Q';
//             if(NQueenUtil(board, k+1)){
//                 return true;
//             }
//             board[k][i]='_';
//         }
//     }
//     return false;
// }
//
// void NQueen(char board[n][n]){
//
//     int k=0;
//     if(NQueenUtil(board, k)){
//         cout<<"Possible board is "<<endl;
//         for(int i=0; i<n; ++i){
//             for(int j=0; j<n; ++j){
//                 cout<<board[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//     }else{
//         cout<<"not possible"<<endl;
//     }
//     return;
// }
// bool isparenthesis(char c){
//     if(c==('(' ) || c==( ')')){
//         return true;
//     }else{
//         return false;
//     }
// }
// bool validstring(string s){
//     int c=0;
//     for(int i=0; i<(int)s.length(); ++i){
//         if(s[i]=='('){
//             ++c;
//         }
//         if(s[i]==')'){
//             --c;
//         }
//         if(c<0){
//             return false;
//         }
//     }
//     if(c==0){
//         return true;
//     }
//     return false;
// }
//
// void removeInvalidParenthesis(string s){
//     set<string> visit;
//     queue<string> q;
//     bool level =false;
//     q.push(s);
//     string temp;
//     visit.insert(s);
//     while(!q.empty()){
//         s = q.front(); q.pop();
//         if(validstring(s)){
//             cout<<s<<endl;
//             level = true;
//         }
//         if(level){
//             continue;
//         }
//         for(int i=0; i<s.length(); ++i){
//             if(!isparenthesis(s[i])){
//                 continue;
//             }
//             temp = s.substr(0, i) + s.substr(i+1);
//             if(visit.find(temp) == visit.end()){
//                 q.push(temp);
//                 visit.insert(temp);
//             }
//         }
//     }
// }
// vi prime;
// vi ans;
// bool isprime(int n){
//     for(int i=2; i*i<=n; ++i){
//         if(n%i==0){
//             return false;
//         }
//     }
//     return true;
// }
// void primesum(int n, int s, int pos, int sum){
//     if(sum==s && ans.size()==n){
//         for(int i=0;i <ans.size(); ++i){
//             cout<<ans[i]<<" ";
//         }
//         cout<<endl;
//         return;
//     }
//     if(sum>s || pos == prime.size()) return;
//     primesum(n, s, pos+1, sum);
//     ans.pb(prime[pos]);
//     primesum(n, s, pos+1, sum+prime[pos]);
//     ans.pop_back();
// }
// void allPrime(int n, int s, int p){
//
//     for(int i= p+1; i<=s; ++i){
//         if(isprime(i)){
//             prime.pb(i);
//         }
//     }
//     if(prime.size()<n){
//         return;
//     }
//     primesum(n, s, 0, 0);
// }

// void greycodeUtil(int n, int num, vi &res){
//     if(n==0){
//         res.pb(num);
//         return;
//     }
//     greycodeUtil(n-1, num, res);
//     num = (num ^ (1<<(n-1)));
//     greycodeUtil(n-1, num, res);
//     num = (num ^ (1<<(n-1)));
//
// }
//
// void greycode(){
//     int n=3;
//     int num=0;
//     vi res;
//     greycodeUtil(n, num, res);
//     for(int i=0; i<(int)res.size(); ++i){
//         cout<<res[i]<<endl;
//     }
// }

// void printpathutil(int matrix[3][3], int i, int j, int m, int n, vi ans, vvi &final){
//     if(i==m-1 && j==n-1){
//         ans.pb(matrix[i][j]);
//         final.pb(ans);
//         return;
//     }
//     if(i==m){
//         return;
//     }
//     if(j==n){
//         return;
//     }
//     ans.pb(matrix[i][j]);
//     printpathutil(matrix, i+1, j, m, n, ans, final);
//
//     printpathutil(matrix, i, j+1, m, n, ans, final);
//
// }
//
// void printAllPaths(int matrix[3][3], int n, int m){
//     vi ans;
//     vvi final;
//     printpathutil(matrix, 0, 0, n, m, ans, final);
//     for(int i=0; i<(int)final.size(); ++i){
//         for(int j=0; j <final[i].size(); ++j){
//             cout<<final[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    //code part
    //solve here
    // int n =3, m=3;
    // int matrix[n][N] = {
    //     {1, 2, 3},
    //     {2, 3, 1},
    //     {1, 1, 1}
    // };
    // printMinSources(matrix, n, m);
    // int num1 =1033, num2 = 8179;
    // cout<<shortestpath(num1, num2)<<endl;
    //waterjugproblem(5, 3, 4);
    //printBinaryPalindrome(8, 3);
    // int m1 = 5, n1 = 5, k1 = 2, r1 = 1;
    // vector<int> X1 = {1, 3};
    // vector<int> Y1 = {3, 3};
    // if (isPossible(m1, n1, k1, r1, X1, Y1))
    //     cout << "Possible" << endl;
    // else
    //     cout << "Not Possible" << endl;
    //findheightofTree();

    // int graph[V][V] = {
    //     { 0, 1, 1, 1 },
    //     { 1, 0, 1, 0 },
    //     { 1, 1, 0, 1 },
    //     { 1, 0, 1, 0 },
    // };
    // mcolouringBacktrack(graph);
    // int graph[V][V] = {{0, 1, 0, 1, 0},
    //                     {1, 0, 1, 1, 1},
    //                     {0, 1, 0, 0, 1},
    //                     {1, 1, 0, 0, 1},
    //                     {0, 1, 1, 1, 0}
    //                 };
    // hamcycle(graph);

    // int grid[V][V] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
    //                    { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
    //                    { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
    //                    { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
    //                    { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
    //                    { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
    //                    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
    //                    { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
    //                    { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
    //                };
    // soduku(grid);
    // char board[n][n]={
    //     {'_', '_', '_', '_'},
    //     {'_', '_', '_', '_'},
    //     {'_', '_', '_', '_'},
    //     {'_', '_', '_', '_'},
    // };
    // NQueen(board);
    // string expression = "()v)";
    // removeInvalidParenthesis(expression);
    // int s = 54, n = 2, p = 3;
    // allPrime(n, s, p);
    //greycode();
    // int mat[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // printAllPaths(mat, 3, 3);
    





	return 0;
}
