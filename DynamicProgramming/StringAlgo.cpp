 #include <bits/stdc++.h>
#include <regex>
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
typedef vector<vs> vvs;
typedef vector<bool> vb;
typedef vector< vb > vvb;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef map<string, int> msi;

int pretable[N];
#define NoChar 256

void KMPsearch(string txt, string pattern){
    int n = txt.size();
    int m = pattern.size();
    int i=0;
    int j=0;
    while(i<n){
        if(pattern[j] == txt[i]){
            i++;
            j++;
        }
        if(j==m){
            cout<<"Pattern found at "<<i-j<<endl;
            j = pretable[j-1];
        }
        else if(i<n && pattern[j] != txt[i]){
            if(j!=0){
                j = pretable[j-1];
            }else{
                i = i+1;
            }
        }
    }
}

int* lps(string pattern){
    int len =0;
    pretable[0]=0;
    int i=1;
    while(i<pattern.size()){
        if(pattern[i] == pattern[len]){
            len++;
            pretable[i++] = len;
        }else{
            if(len !=0){
                len = pretable[len-1];
            }else{
                pretable[i++] =0;
            }
        }
    }
    return pretable;
}

// void RobinKarp(string txt, string pattern){
//     const int d =256;
//     int q = 11;
//     int n=txt.size();
//     int m=pattern.size();
//     int i, j;
//     int p=0;
//     int t=0;
//     int h=1;
//     for(int i=0; i<m-1; ++i){
//         h=(h*d)%q;
//     }
//     for( i=0; i<m; ++i){
//         p = (d*p + pattern[i])%q;
//         t = (d*t + txt[i])%q;
//     }
//     for( i=0; i<=n-m; ++i){
//         if(p==t){
//             for( j=0; j<m; ++j){
//                 if(pattern[j] != txt[i+j]){
//                     break;
//                 }
//             }
//             if(j==m){
//                 cout<<"Pattern at index "<<i<<endl;
//             }
//         }
//         if(i<n-m){
//             t=(d*(t-txt[i]*h) + txt[i+m])%q;
//             if(t<0){
//                 t=t+q;
//             }
//         }
//     }
// }
//
// void optimisedsearch(string txt, string pattern){
//     int n = txt.size();
//     int m =pattern.size();
//     int i=0; int j;
//     while(i<=n-m){
//         for(j=0; j<m; ++j){
//             if(txt[i+j] != pattern[j]){
//                 break;
//             }
//         }
//         if(j==m ){
//             cout<<"Pattern found at "<<i<<endl;
//             i= i+m;
//         }
//         else if(j==0){
//             i=i+1;
//         }else{
//             i=i+j;
//         }
//     }
// }
// void preprocess_strong_suffix(int *shiftt, int *bposs, string pattern, int m){
//     int i=m;
//     int j=m+1;
//     bposs[i]=j;
//     while(i>0){
//         while(j<=m && pattern[i-1]!=pattern[j-1]){
//             if(shiftt[j]==0){
//                 shiftt[j]=j-i;
//             }
//             j=bposs[j];
//         }
//         i--; j--;
//         bposs[i]=j;
//     }
// }
//
// void preprocess_case2(int *shiftt, int *bposs, string pattern, int m){
//     int i,j;
//      j=bposs[0];
//     for(i=0; i<=m; ++i){
//         if(shiftt[i]==0){
//             shiftt[i] = j;
//         }
//         if(i==j){
//             j=bposs[j];
//         }
//     }
// }
//
//
// void search(string txt, string pattern){
//     int s=0;
//     int j;
//     int n=txt.size();
//     int m=pattern.size();
//     int bpos[m+1];
//     int shift[m+1];
//     for(int i=0; i<=m; ++i){
//         shift[i]=0;
//     }
//     preprocess_strong_suffix(shift, bpos, pattern, m);
//     preprocess_case2(shift, bpos, pattern, m);
//
//     while(s<=n-m){
//         j=m-1;
//         while(j>=0 && pattern[j] == txt[s+j]){
//             j--;
//         }
//         if(j<0){
//             cout<<"Pattern at "<<s<<endl;
//             s +=shift[0];
//         }else{
//             s +=shift[j+1];
//         }
//     }
// }
// namespace trie{
//     using namespace std;
//     const int Alpha = 26;
//     struct trieNode{
//         trieNode *child[Alpha];
//         bool isendofword;
//     };
//     trieNode* newNode(){
//         trieNode *node = new trieNode;
//         node->isendofword = false;
//         for(int i=0; i<Alpha; ++i){
//             node->child[i] = nullptr;
//         }
//         return node;
//     }
//     void insert(trieNode* root, string key){
//         trieNode *temp = root;
//
//         for(int i=0; i<key.size(); ++i ){
//             int index = key[i] - 'a';
//             if(!(temp->child[index])){
//                 temp->child[index] = newNode();
//             }
//             temp = temp->child[index];
//         }
//         temp->isendofword = true;
//     }
//     bool searchword(trieNode *root, string key){
//         trieNode *temp = root;
//         for(int i=0; i<key.size(); ++i){
//             int index = key[i]-'a';
//             if(!temp->child[index]){
//                 return false;
//             }
//             temp = temp->child[index];
//         }
//         return (temp != nullptr && temp->isendofword);
//     }
//
//     void display(trieNode *root, int l, string key){
//
//         if(root->isendofword ){
//             cout<<key<<endl;
//         }
//         int i;
//         for( i=0; i<Alpha; ++i){
//             if(root->child[i]){
//                 char c = i+'a';
//                 display(root->child[i], i, key+c);
//
//             }
//         }
//
//     }
//
//     bool isEmpty(trieNode *root){
//         for(int i=0; i<Alpha;++i){
//             if(root->child[i]){
//                 return false;
//             }
//         }
//         return true;
//     }
//     trieNode* deletetrie(trieNode *root, int l, string k){
//         if(!root){
//             return nullptr;
//         }
//         if(l==k.size()){
//             if(root->isendofword){
//                 root->isendofword = false;
//             }
//             if(isEmpty(root)){
//                 delete(root);
//                 root = nullptr;
//             }
//             return root;
//         }
//         int inx = k[l] - 'a';
//         root->child[inx] = deletetrie(root->child[inx], l+1, k);
//         if(isEmpty(root) && root->isendofword){
//             delete(root);
//             root = nullptr;
//         }
//         return root;
//     }
//     void suggestions(trieNode *root, string pre){
//
//         if(root->isendofword){
//             cout<<pre<<endl;
//         }
//         if(isEmpty(root)){
//             return;
//         }
//         for(int i=0; i<Alpha; ++i){
//             if(root->child[i]){
//             char c =  i+'a';
//             suggestions(root->child[i], pre+c);
//             }
//         }
//
//     }
//
//     int Autosuggestions(trieNode *root, string q){
//
//         for(int i=0; i<q.size(); ++i){
//             int inx = q[i] - 'a';
//             if(!root->child[inx]){
//                 return 0;
//             }
//             root = root->child[inx];
//         }
//         bool issword = (root->isendofword == true);
//         if(isEmpty(root) && issword){
//             cout<<q<<endl;
//             return -1;
//         }
//         if(!isEmpty(root)){
//             string pre = q;
//             suggestions(root, pre);
//             return 1;
//         }
//         return 0;
//     }
//
// }
//
// namespace trieRec{
//     using namespace std;
//     const int alpha = 26;
//     struct trieRNode{
//         char data;
//         bool isendofword=false;
//         trieRNode *child[alpha];
//     };
//     trieRNode *insertRtrie(trieRNode *root,unsigned int i, string key){
//         if(key.size()==0 ) return nullptr;
//         int index = key[i] -'a';
//         if(!root ){
//             trieRNode *newNode = new trieRNode;
//             newNode->data = key[i];
//             for(int j=0; j<alpha; ++j){
//                 newNode->child[j] = nullptr;
//             }
//             //assert(i+1 != key.size());
//             if(i+1 == key.size()){
//                 newNode->isendofword = true;
//             }else{
//                 newNode->child[index] = insertRtrie(newNode->child[index], i+1, key);
//             }
//             return newNode;
//         }
//         root->data = key[i];
//         if(i+1 == key.size()) {
//             root->isendofword = true;
//             return root;
//         }
//         root->child[index] = insertRtrie(root->child[index], i+1, key);
//         return root;
//     }
//     int searchRtrie(trieRNode *root, int i, string key){
//         if(!root) return -1;
//
//         if(i+1 == key.size()){
//             if(root->isendofword){
//                 return 1;
//             }else{
//                 return -1;
//             }
//         }
//         int index = key[i] -'a';
//         if(root->data == key[i]){
//             return searchRtrie(root->child[index], i+1, key);
//         }else{
//             return -1;
//         }
//     }
// }
//
// namespace suffixArr{
//     using namespace std;
//     struct suffixarray{
//         int idx;
//         string s;
//     };
//     int cmp(suffixarray a, suffixarray b){
//         int c = (a.s).compare((b.s));
//         if(c<0) {
//             return 1;
//         }
//         return 0;
//
//     }
//     int *buildsuffix(string txt){
//         suffixarray sarr[txt.size()];
//         for(int i=0; i<txt.size(); ++i){
//             sarr[i].idx =i;
//             sarr[i].s = txt.substr(i, txt.size()-i);
//         }
//         sort(sarr, sarr+txt.size(), cmp);
//         int *arr = new int[txt.size()];
//         for(int i=0; i<txt.size(); ++i){
//             arr[i] = sarr[i].idx;
//         }
//         return arr;
//     }
//     bool search(int *ar, string txt, string pat){
//         int low = 0;
//         int high = txt.size()-1;
//         while(low<=high){
//             int mid = low + (high-low)/2;
//             int c = pat.compare(0, pat.size(), txt, ar[mid], pat.size() );
//             if(c ==0){
//                 return true;
//             }else if(c<0){
//                 high = mid-1;
//             }else{
//                 low = mid+1;
//             }
//         }
//         return false;
//     }
//
// }
//
// void computeFunc(string pat, int m, int dp[][NoChar]){
//     int i, lps=0, x;
//     for(x =0; x<NoChar; ++x){
//         dp[0][x] = 0;
//     }
//     dp[0][pat[0]]=1;
//     for( i=1; i<=m; ++i){
//         for(x=0; x<NoChar; ++x){
//                 dp[i][x] = dp[lps][x];
//             }
//         dp[i][pat[i]] = i+1;
//         if(i<m){
//             lps = dp[lps][pat[i]];
//         }
//     }
// }
//
// void effiecientFiniteAutomata(string txt, string pattern){
//     int m = pattern.size();
//     int n=txt.size();
//     int dp[m+1][NoChar];
//     computeFunc(pattern, m, dp);
//     int i, j=0;
//     for( i=0; i<n; ++i){
//         j = dp[j][txt[i]];
//         if(j==m){
//             cout<<"Pattern found at index "<<i-m+1<<endl;
//         }
//
//     }
// }
//
// int getstate(string patt, int m, int state, int x){
//     if(state<m && x==patt[state]){
//         return state+1;
//     }
//     int ns, i;
//     for(ns = state; ns>0; ns--){
//         if(patt[ns-1] == x){
//             for(i = 0; i <ns-1; ++i){
//                 if(patt[i] != patt[state-ns+1+i]){
//                     break;
//                 }
//             }
//             if(i==ns-1){
//                 return ns;
//             }
//         }
//     }
//     return 0;
// }
//
// void computeFuncforfinite(string patt, int m, int dp[][NoChar]){
//     int x, state;
//     for(state =0; state<=m; ++state){
//         for(x=0; x<NoChar; ++x){
//             dp[state][x] = getstate(patt, m, state, x);
//         }
//     }
// }
//
// void finiteAutomata(string txt, string pat){
//     int m = pat.size();
//     int n= txt.size();
//     int dp[m+1][NoChar];
//     computeFuncforfinite(pat, m, dp);
//     int i, state=0;
//     for(i =0; i<n; ++i){
//         state = dp[state][txt[i]];
//         if(state == m ){
//             cout<<"Pattern found at index "<<i-m+1<<endl;
//         }
//     }
// }
//
// int longestpalidromicsubsequence(string txt, int i, int j){
//     if(txt.size()==0) return 0;
//     if(i==j) return 1;
//     if(txt[i] == txt[j] && i+1==j ) return 2;
//     if(txt[i] == txt[j]) return longestpalidromicsubsequence(txt, i+1, j-1)+2;
//     return max(longestpalidromicsubsequence(txt, i+1, j), longestpalidromicsubsequence(txt, i, j-1));
// }
//
// int lcs(string x, string y, int m, int n){
//     if(m==0 || n==0) return 0;
//     if(x[m-1] == y[n-1]) return 1 + lcs(x, y, m-1, n-1);
//     else{
//         return max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));
//     }
// }
//
// int lcsubstring(string x, string y, int m, int n, int count ){
//     int lcscount1, lcscount2, lcscount3;
//     if(m<=0 || n<=0){
//         return count ;
//     }
//     lcscount1 = count;
//     if(x[m-1] == y[n-1]){
//         lcscount1 =  lcsubstring(x, y, m-1, n-1, count+1);
//     }
//     lcscount2 = lcsubstring(x, y, m-1, n, 0);
//     lcscount3 = lcsubstring(x, y, m, n-1, 0);
//     return max(lcscount1, max(lcscount2, lcscount3));
// }
//
// int lcssubstringdp(string x, string y, int m, int n){
//     int result=0;
//     int dp[m+1][n+1];
//     for(int i=0; i <=m; ++i){
//         for(int j=0; j<=n; ++j){
//             if(i==0 || j==0){
//                 dp[i][j]=0;
//             }else if(x[i-1] == y[j-1]){
//                 dp[i][j] = dp[i-1][j-1] +1;
//                 result = max(result, dp[i][j]);
//             }else{
//                 dp[i][j] = 0;
//             }
//         }
//     }
//     return result;
// }
//
// int longestPalindromeSubstring(string s, int i, int j, int count){
//     int lcpalsub1, lcpalsub2, lcpalsub3, lcpalsub4, lcpalsub5;
//     if(i>j){
//         return count;
//     }
//     if(i==j){
//         count+1;
//     }
//     // lcpalsub1 = count;
//     // lcpalsub2 = count;
//     // lcpalsub3 =count;
//     if(s[i]==s[j]){
//         lcpalsub1= longestPalindromeSubstring(s, i+1, j-1, count+2);
//         lcpalsub2 = longestPalindromeSubstring(s, i, j-1, 0);
//         lcpalsub3 = longestPalindromeSubstring(s, i+1, j, 0);
//         return max(lcpalsub1, max(lcpalsub2, lcpalsub3));
//     }
//     lcpalsub4 = longestPalindromeSubstring(s, i+1, j, 0);
//     lcpalsub5 = longestPalindromeSubstring(s, i, j-1, 0);
//     return max(lcpalsub4, lcpalsub5);
// }
//
// int longestPalindromeSubstringDp(string str, int n){
//     bool dp[n][n];
//     memset(dp, false, sizeof(dp));
//     for(int i=0; i<n; ++i){
//         dp[i][i] = true;
//     }
//     int subl = 2;
//     int maxl=1;
//     int start=0;
//     for(int i=0; i<n-subl+1; ++i){
//         if(str[i]==str[i+1]){
//             dp[i][i+1]=true;
//             start=i;
//             maxl=2;
//         }
//     }
//     for(subl=3; subl<=n; subl++){
//         for(int i=0; i < n-subl+1; ++i){
//             int j= i+subl-1;
//             if(dp[i+1][j-1] && str[i]==str[j]){
//                 dp[i][j]= true;
//                 if(maxl<subl){
//                     start = i;
//                     maxl = subl;
//                 }
//             }
//         }
//     }
//     return maxl;
//
// }
//
// // int longestpalidromicsubsequence(string str, int i, int j){
// //     int lpss1, lpss2, lpss3;
// //     if(i==j){
// //         return 1;
// //     }
// //     if(i+1 == j && str[i]==str[j]){
// //         return 2;
// //     }
// //     if(str[i]==str[j]){
// //         lpss1 = longestpalidromicsubsequence(str, i+1, j-1) +2;
// //         return lpss1;
// //     }
// //     lpss2 = longestpalidromicsubsequence(str, i+1, j);
// //     lpss3 = longestpalidromicsubsequence(str, i, j-1);
// //
// //     return max(lpss2, lpss3);
// // }
//
// int longestpalidromicsubsequenceDp(string str, int n){
//     int dp[n][n];
//     for(int i=0; i<n; ++i){
//         dp[i][i] = 1;
//     }
//
//     for(int strlen = 2; strlen<=n; ++strlen){
//         for(int i=0; i<n-strlen+1; ++i){
//             int j = i + strlen -1;
//             if(str[i]==str[j] && strlen == 2){
//                 dp[i][j] =2;
//             }else if(str[i]==str[j]){
//                 dp[i][j] = dp[i+1][j-1] +2;
//             }else{
//                 dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
//             }
//         }
//     }
//     return dp[0][n-1];
// }
//
// int lcsdp(string x, string y, int m, int n){
//     int dp[m+1][n+1];
//     int i, j;
//     for(i=0; i<=m; ++i){
//         for(j=0; j<=n; ++j){
//             if(i==0 || j==0){
//                 dp[i][j]=0;
//             }else if(x[i]==y[j]){
//                 dp[i][j] = 1 + dp[i-1][j-1];
//             }else{
//                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//     }
//     return dp[m][n];
// }
//
// void lcsprint(string x, string y, int m, int n){
//     int dp[m+1][n+1];
//     int i, j;
//     for(i=0; i<=m; ++i){
//         for(j=0; j<=n; ++j){
//             if(i==0 || j==0){
//                 dp[i][j]=0;
//             }else if(x[i]==y[j]){
//                 dp[i][j] = 1 + dp[i-1][j-1];
//             }else{
//                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//     }
//     cout<<dp[m][n]<<endl;
//     int index = dp[m][n];
//     string z;
//     int a=m; int b=n;
//     while(a>0 && b>0){
//         if(x[a-1] == y[b-1]){
//             z= x[a-1] + z;
//             a--; b--; index--;
//         }
//         else if(dp[a-1][b] > dp[a][b-1]){
//             a--;
//         }else{
//             b--;
//         }
//     }
//     cout<<z<<endl;
// }
//
//
// void manachersalgorithm(string ss){
//      string str;
//      string z ="*";
//     for(int i=0; i<ss.size(); ++i){
//         str += z+ss[i];
//     }
//     str +=z;
//     int lps[str.size()];
//     int c =0;
//     int r =0;
//     int maxlen=0;
//     int maxc=0;
//     int len = str.size();
//     for(int i=0; i<len; ++i){
//         lps[i]=0;
//     }
//     for(int i=0; i<len; ++i){
//         int mirror = 2*c-i;
//         if(i<r){
//             lps[i] = min(r-i, lps[mirror]);
//         }
//         int a = i + (1+lps[i]);
//         int b = i - (1+lps[i]);
//         while(a<len && b>=0 && str[a] == str[b]){
//             lps[i]++;
//             a++;
//             b--;
//         }
//         if(i+lps[i]>r){
//             c = i;
//             r = i+lps[i];
//         }
//         if(lps[i]>maxlen){
//             maxlen = lps[i];
//             maxc = i;
//         }
//     }
//     cout<<endl;
//     int start = (maxc - maxlen)/2;
//     int end = start + maxlen -1;
//     for(int i=start; i<=end; ++i){
//         cout<<ss[i];
//     }
// }
//


//
// void checkPalindrome(string s){
//     int len = s.size();
//     const int d = 256;
//     const int prime = 103;
//     if(len ==0){
//         cout<<"No string "<<endl;
//         return;
//     }
//     else if(len == 1){
//         cout<<"sting palindrome"<<endl;
//         return;
//     }
//     int j=0;
//     int i=0;
//     int h=1;
//     int firstrev = s[0]%prime;
//     int second = s[1]%prime;
//         for( i=1; i<len; ++i){
//             if(firstrev == second){
//                 for( j=0; j<(i/2); ++j){
//                     if(s[i] != s[i-j]){
//                         break;
//                     }
//                 }
//                 if(j==(i/2)){
//                     cout<<"string palindrome = "<<endl;
//                     for(int k=0; k<=i; ++k){
//                         cout<<s[k];
//                     }
//                     cout<<endl;
//                 }else{
//                     cout<<"string not palindrome = "<<endl;
//                     for(int k=0; k<=i; ++k){
//                         cout<<s[k];
//                     }
//                     cout<<endl;
//                 }
//             }
//             else{
//                 cout<<"string not palindrome = "<<endl;
//                 for(int k=0; k<=i; ++k){
//                     cout<<s[k];
//                 }
//                 cout<<endl;
//             }
//             if(i != len-1){
//                 if(i%2){
//                     second = (d*(second + prime - s[(i+1)/2]*h))%prime + s[i+1]%prime;
//                 }else{
//                     h = (h*d)%prime;
//                     firstrev = (firstrev + h*s[i/2])%prime;
//                     second = (second*d + s[i+1])%prime;
//                 }
//             }
//         }
// }
//
// void z_algo(string s){
//     int n = (int) s.length();
//     vector<int> z(n);
//     z[0] = 0; // z[0] = 0 or z[0] = n according to problem statement;
//     for(int i=1; i<n; ++i){
//         while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
//             ++z[i];
//         }
//     }
//     for(int i : z){
//         cout<<i<<endl;
//     }
// }
//
// void z_function(string s, string patt){
//     patt = patt + "$";
//     s = patt + s;
//     int n = (int)s.length();
//     vector<int> z(n);
//     z[0]=0;
//     int L=0, R=0;
//     for(int i=1; i<n;++i){
//         if(i<=R){
//             z[i]=min(z[i-L], R-i+1);
//         }else{
//             z[i]=0;
//         }
//         while(i + z[i]<n && s[z[i]] == s[i+z[i]]){
//             ++z[i];
//         }
//         if(i+z[i]-1>R){
//             L=i;
//             R = i+z[i]-1;
//         }
//     }
//
//     cout<<"Z function = "<<s<<endl;
//     for(int i=0; i<n; ++i){
//         if(z[i]==(int)patt.length()-1){
//             cout<<i<<endl;
//         }
//     }
// }
//
//
// namespace ahokarosick{
//     using namespace std;
//     struct node{
//         map<char, node*> child;
//         node* suffix_link;
//         node* output_link;
//         int pattern_ind;
//     };
//
//     node* add_node(){
//         node* temp = new node;
//         temp->suffix_link= nullptr;
//         temp->output_link = nullptr;
//         temp->pattern_ind = -1;
//         return temp;
//     }
//
//     void build_trie(node* root, vs &patterns){
//         for(int i=0; i<patterns.size(); ++i){
//             node* cur = root;
//             for(auto c : patterns[i]){
//                 if(cur->child.count(c)){
//                     cur = cur->child[c];
//                 }else{
//                     node* new_child = add_node();
//                     cur->child.insert({c, new_child});
//                     cur = new_child;
//                 }
//             }
//             cur->pattern_ind = i;
//         }
//     }
//
//     void build_suffix_and_output_links(node* root){
//         root->suffix_link = root;
//         queue<node*> q;
//         for(auto &it : root->child){
//             q.push(it.second);
//             it.second->suffix_link = root;
//         }
//         while(q.size()){
//             node* cur_state = q.front();
//             q.pop();
//             for(auto &it : cur_state->child){
//                 char c = it.first;
//                 node* temp = cur_state->suffix_link;
//                 while(temp->child.count(c)==0 && temp != root){
//                     temp = temp->suffix_link;
//                 }
//                 if(temp->child.count(c)){
//                     it.second->suffix_link = temp->child[c];
//                 }else{
//                     it.second->suffix_link =root;
//                 }
//                 q.push(it.second);
//             }
//             if(cur_state->suffix_link->pattern_ind>=0){
//                 cur_state->output_link = cur_state->suffix_link;
//             }else{
//                 cur_state->output_link = cur_state->suffix_link->output_link;
//             }
//         }
//     }
//
//     void search_pattern(node* root, string &txt, vvi &indices){
//         node* parent = root;
//         for(int i=0; i<txt.length(); ++i){
//             char c = txt[i];
//             if(parent->child.count(c)){
//                 parent = parent->child[c];
//                 if(parent->pattern_ind>=0){
//                     indices[parent->pattern_ind].pb(i);
//                 }
//                 node* temp = parent->output_link;
//                 while(temp != nullptr){
//                     indices[temp->pattern_ind].pb(i);
//                     temp = temp->output_link;
//                 }
//             }else{
//                 while(parent !=root && parent->child.count(c)==0){
//                     parent = parent->suffix_link;
//                 }
//                 if(parent->child.count(c)) i--;
//             }
//         }
//     }
// }
//
// namespace suffixArrayOptimised{
//     using namespace std;
//     struct suffix{
//         int index;
//         int rank[2];
//     };
//
//     bool comp(suffix a, suffix b){
//         if(a.rank[0] == b.rank[0]){
//             if(a.rank[1] < b.rank[1]){
//                 return true;
//             }else{
//                 return false;
//             }
//         }else{
//             if(a.rank[0] < b.rank[0]){
//                 return true;
//             }else{
//                 return false;
//             }
//         }
//     }
//
//
//     int *buildsuffixArray(string txt, int n){
//         struct suffix suffixes[n];
//         for(int i=0; i<n; ++i){
//             suffixes[i].index = i;
//             suffixes[i].rank[0] = txt[i] -'a';
//             suffixes[i].rank[1] = ((i+1)<n) ? (txt[i+1]-'a') : -1;
//         }
//         sort(suffixes, suffixes+n, comp);
//         int ind[n];
//         for(int k = 4; k<2*n; k *=2){
//             int rank=0;
//             int prevrank = suffixes[0].rank[0];
//             suffixes[0].rank[0] = rank;
//             ind[suffixes[0].index] = 0;
//             for(int i=1; i<n; ++i){
//                 if(suffixes[i].rank[0] == prevrank && suffixes[i].rank[1] == suffixes[i-1].rank[1]){
//                     prevrank = suffixes[i].rank[0];
//                     suffixes[i].rank[0] = rank;
//                 }else{
//                     prevrank = suffixes[i].rank[0];
//                     suffixes[i].rank[0] = ++rank;
//                 }
//                 ind[suffixes[i].index] = i;
//             }
//             for(int i=0; i<n; ++i){
//                 int nextindex = suffixes[i].index + k/2;
//                 suffixes[i].rank[1] = (nextindex <n) ? suffixes[ind[nextindex]].rank[0] : -1;
//             }
//             sort(suffixes, suffixes+n, comp);
//         }
//         int *sa = new int[n];
//         for(int i=0; i<n; ++i){
//             sa[i] = suffixes[i].index;
//         }
//         return sa;
//     }
//
//     int* lcp_kasai(string txt, int *arr, int n){
//         //int n = (*(&arr + 1)-arr);
//         int *lcp = new int[n];
//         int invsuff[n];
//         for(int i=0; i<n; ++i){
//             invsuff[arr[i]]=i;
//         }
//         int k=0;
//         for(int i=0; i<n; ++i){
//             if(invsuff[i]==n-1){
//                 k=0;
//                 continue;
//             }
//             int j = arr[invsuff[i]+1];
//             while(i+k<n && j+k<n && txt[i+k]==txt[j+k]){
//                 k++;
//             }
//             lcp[invsuff[i]] = k;
//             if(k>0){
//                 k--;
//             }
//         }
//         return lcp;
//     }
// }
//


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//code part
    string txt="AABAACAADAABAAABAA";
    string pattern = "AABAA";

    int *table = lps(pattern);
    for(int i=0; i<pattern.size(); ++i){
        cout<<table[i]<<endl;
    }
    KMPsearch(txt, pattern);
    //RobinKarp(txt, pattern);
    //optimisedsearch(txt, pattern);
    //search(txt, pattern);
    // string keys[] = { "the", "a", "there", "answer", "any", "by", "bye", "their" };
    // int n = (*(&keys+1) -keys);
    // trie::trieNode *root = trie::newNode();
    // for(int i=0; i<n; ++i){
    //     trie::insert(root, keys[i]);
    // }
    // string kkk = "th";
    //trie::searchword(root, kkk) ? cout<<"Present"<<endl : cout<<"Not present"<<endl;
    // string m;
    // trie::display(root, 0, m);
    // trie::deletetrie(root, 0, kkk );
    // trie::display(root, 0, m);
    // int j = trie::Autosuggestions(root, kkk);

    // string k = "star";
    // string kk = "st";
    // trieRec::trieRNode *root = nullptr;
    // root =trieRec::insertRtrie(root, 0, k);
    // root =trieRec::insertRtrie(root, 0, kk);
    // if(root){
    //     cout<<root<<endl;
    // }
    // if(trieRec::searchRtrie(root, 0, kk) == 1){
    //     cout<<"present"<<endl;
    // }else{
    //     cout<<"not present"<<endl;
    // }



    // LIS || LCS || LCS    (S - subsequence, substring)



    // string x= "AGGTABBB";
    // string y ="GXTXAYBBB";
    // int m = x.size();
    // int n = y.size();
    // string ss = "forgeeksskeegfor";
    // string x = "GEEKSFORGEEKS";
    // int sx = x.size();
    // int s = ss.size();
    //cout<<longestPalindromeSubstring(ss, 0, s-1, 0)<<endl;
    //cout<<longestPalindromeSubstringDp(ss, s)<<endl;
    //cout<<longestpalidromicsubsequence(x, 0, sx-1)<<endl;
    //cout<<longestpalidromicsubsequenceDp(x, sx)<<endl;
    //cout<<lcsubstring(x, y, m, n, 0)<<endl;  // O(n *m^2)
    //cout<<lcssubstringdp(x, y, m, n)<<endl;   // O(n*m)
    //cout<<lcs(x, y, m, n)<<endl;
    //lcsprint(x, y, m, n);
    //cout<<lcsdp(x,y, m, n)<<endl;

    // string s = "bananan";
    // string p="nan";
    // int *b = suffixArr::buildsuffix(s); //O( n^2logn)
    // // search in suffix array in O(m*logn)
    // suffixArr::search(b, s, p) ? cout<<"Found"<<endl : cout<<"Not found"<<endl;
    //finiteAutomata(txt, pattern); //O(m^3*NumberOfChar)
    //effiecientFiniteAutomata(txt, pattern); //O(m*NumberOfChar)
    //string seq = "GEEKSFORGEEKS";
    //int n = seq.size();
    //int k = longestpalidromicsubsequence(seq, 0, n-1);

    // string s ="forgeeksskeegfor";
    // manachersalgorithm(s);

    // string s = "aabaacaabaa";
    // checkPalindrome(s);

    // string str = "aabcaabxaaaz";
    // string patt = "aab";
    //z_algo(str);
    //z_function(str, patt);

    // int k;
    // cin>>k;
    // string txt;
    // vs patterns(k);
    //
    // for(int i=0; i<k; ++i){
    //     cin>>patterns[i];
    // }
    // cin>>txt;

    // ahokarosick::node* root = ahokarosick::add_node();
    // ahokarosick::build_trie(root, patterns);
    // ahokarosick::build_suffix_and_output_links(root);
    // vvi indices(k, vi());
    // ahokarosick::search_pattern(root, txt, indices);
    //
    // for(int i=0; i<k;++i){
    //     cout<<"Total occurences of "<<patterns[i]<<" : "<<indices[i].size()<<endl;
    //     if(indices[i].size()) cout<<" Occurences at position: ";
    //     for(auto &j : indices[i]){
    //         cout<<j - patterns[i].length() + 1<<" ";
    //     }
    //     cout<<endl;
    //     cout<<endl;
    // }


    // string s = "banana";  // O(n*logn*logm) version
    // int *sarray = suffixArrayOptimised::buildsuffixArray(s, (int)s.size());
    // cout<<"suffix array of "<<s<<endl;
    // for(int i=0; i< s.size(); ++i){
    //     cout<<sarray[i]<<" ";
    // }
    // cout<<endl;
    // int *lcpp = suffixArrayOptimised::lcp_kasai(s, sarray, (int)s.size());
    // for(int i=0; i< (int)s.size(); ++i){
    //     cout<<lcpp[i]<<" ";
    // }










	return 0;
}
