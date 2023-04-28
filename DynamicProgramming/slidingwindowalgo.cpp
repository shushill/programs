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

int b[N];
void mergee(int arr[], int l, int mid, int r){
    int n = r-l+1;

    int l1 =l;
    int l2 = mid+1;
    int i=l;
    while(l1<=mid && l2<=r){
        if(arr[l1]<=arr[l2]){
            b[i]=arr[l1];
            i++;
            l1++;
        }else{
            b[i]= arr[l2];
            i++;
            l2++;
        }
    }
    while(l1<=mid){
        b[i]=arr[l1];
        i++;
        l1++;
    }
    while(l2<=r){
        b[i]=arr[l2];
        i++;
        l2++;
    }
    i=l;
    while(i<=r){
        arr[i]=b[i];
        i++;
    }
}

void mergesortRecurr(int arr[], int l, int r){
    int mid;
    if(l<r){
     mid = l + (r-l)/2;
    mergesortRecurr(arr, l, mid);
    mergesortRecurr(arr, mid+1, r);
    mergee(arr, l, mid, r);
    }
    return;
}


int partition(int arr[], int low, int high){
    int k = arr[high];
    int i=low;
    int j=high-1;
    int mid;
    do{
        while(arr[i]<k){
            i++;
        }
        while(arr[j]>=k){
            j--;
        }
        if(i<j){
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }while(i<j);
    int inx = i;
     int t = arr[i];
     arr[i] = k;
     arr[high] = t;
     return inx;
}


int partitionn(int arr[], int l, int r){
    int k = arr[l];
    int i=r+1;
    for(int j=r; j >=l+1; --j){
        if(arr[j] > k){
            i--;
            int t=arr[j];
            arr[j] =arr[i];
            arr[i] = t;
        }
    }
    int tmp=arr[i-1];
    arr[i-1] = arr[l];
    arr[l] = tmp;
    return (i-1);
}

void quickssort(int arr[], int l, int r){
    if(l < r){
        int pi = partitionn(arr, l, r);
        quickssort(arr, l, pi-1);
        quickssort(arr, pi+1, r);
    }
    return;
}


string findsubstring(string str, string patt){
    int n = str.size();
    int m = patt.size();
    if(n<m){
        cout<<"Not possible"<<endl;
        return "";
    }
    unordered_map<char, int> table;
    for(int i=0; i<m; ++i){
        table[patt[i]]++;
    }
    int begin=0, end=0;
    int counter = table.size();
    int len = INF;
    string ans="";

    while(end < n){
        char endchar = str[end];
        if(table.find(endchar) != table.end()){
            table[endchar]--;
            if(table[endchar]==0){
                counter--;
            }
        }
        end++;
        while(counter==0){
            if((end-begin)<len){
                len = end-begin;
                ans = str.substr(begin, len);
            }
            char startchar = str[begin];
            if(table.count(startchar) ==1){
                table[startchar]++;
                if(table[startchar]>0){
                    counter++;
                }
            }
            begin++;
        }
    }
    return ans;
}


vi findanagrams(string str, string patt){
    int n = str.size();
    int m = patt.size();
    unordered_map<char, int> table;
    vi ans;
    for(int i=0; i<m; ++i){
        table[patt[i]]++;
    }
    if(n==0 || n<m) return ans;
    int begin=0, end=0;
    int counter = table.size();
    while(end<n){
        char endchar = str[end];
        if(table.count(endchar) == 1){
            table[endchar]--;
            if(table[endchar]==0){
                counter--;
            }
        }
        end++;
        while(counter==0){
            if((end-begin)== m){
                ans.pb(begin);
            }
            char beginchar = str[begin];
            if(table.count(beginchar)==1){
                table[beginchar]++;
                if(table[beginchar]>0){
                    counter++;
                }
            }
            begin++;
        }
    }
    return ans;
}


string longestnonrepetitivesubstring(string str){
    int n = str.length();
    unordered_map<char, int> seen;
    int begin=0, end=0;
    int len=0;
    string ans="";
    while(end<n){
        char current = str[end];
        if(seen.count(current)==1 && seen[current]>=begin){
            begin = seen[current]+1;
        }else{
            seen[current] = end; 
            end++;
        }
        if((end-begin)>len){
            len = end-begin;
            ans = str.substr(begin, len);
        }
    }
    return ans;
}

string longestsubstringwithKdisticnctcharacter(string str){
    int n = str.length();
    //here k=2 distinct character
    unordered_map<char, int> table;
    int begin=0, end=0;
    string ans="";
    int len=0, counter=0;
    while(end<n){
        char current =str[end];
        table[current]++;
        if(table[current]==1) counter++;
        end++;
        while(counter>2){
            char startchar = str[begin];
            if(table.count(startchar)==1){
                table[startchar]--;
                if(table[startchar]==0) counter--;
            }
            begin++;
        }
        if((end-begin+1)>len){
            len = end-begin;
            ans = str.substr(begin, len);
        }
    }
    return ans;
}

vi findsubstring(string str, vs words){
    unordered_map<string, int> table;
    vi ans;
    if(words.size()==0){
        return ans;
    }
    int windowsize=0;

    for(string word : words){
        windowsize +=word.size();
        table[word]++;
    }
    unordered_map<string, int> reference(table);
    int begin=0, end=0;
    int counter = table.size();
    if(str.length()<windowsize) return ans;
    int wordsize = words[0].length();
    for(int i=0; i<wordsize; ++i){
        begin=i;
        end=i;
        table=reference;
        counter = table.size();
        while(end+wordsize-1 < str.length() ){
            string endword = str.substr(end, wordsize);
            if(table.count(endword)==1){
                table[endword]--;
                if(table[endword]==0) counter--;
            }
            if((end+wordsize-begin)==windowsize){
                if(counter==0){
                    ans.pb(begin);
                }
                string firstword = str.substr(begin, wordsize);
                if(table.count(firstword)==1){
                    table[firstword]++;
                    if(table[firstword]>0){
                        counter++;
                    }
                }
                begin +=wordsize;
            }
            end+=wordsize;
        }
    }
    return ans;
}

bool checkinclusion(string str, string patt){
    unordered_map<char, int> table;
    for(char c : patt){
        table[c]++;
    }
    int begin=0, end=0;
    int counter = table.size();
    while(end < str.length()){
        char endchar = str[end];
        if(table.count(endchar)==1){
            table[endchar]--;
            if(table[endchar]==0){
                counter--;
            }
        }
        end++;
        while(counter==0){
            if((end-begin)==patt.length()) return true;
            char startbegin = str[begin];
            if(table.count(startbegin)==1){
                table[startbegin]++;
                if(table[startbegin]>0) counter++;
            }
            begin++;
        }
    }
    return false;
}


string longestsubstringafterKreplacement(string str, int k){
    if(str.length()==0) return 0;
    int low=0, mostFrequentcount=0, maxLength=0;
    string ans="";
    unordered_map<char, int> table;
    for(int high =0; high <str.length(); ++high){
        int currentlettercount = ++table[str[high]];
        mostFrequentcount = max(mostFrequentcount, currentlettercount);
        while(high-low+1 - mostFrequentcount>k){
            table[str[low]]--;
            low++;
        }
        if(high-low+1>maxLength){
            maxLength = high-low+1;
            ans = str.substr(low, high-low+1);
        }

    }
    return ans;
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    //code part
    int arr[] = {3, 8, 2, 9, 6, 1, 5, 4};
    int sz = (*(&arr+1) - arr);
    //mergesortRecurr(arr, 0, sz-1);
    //quickssort(arr, 0, sz-1);
    //string str = "ADOBECODEBANC";
    // string str ="cbaebabacd";
    // string patt = "abc";
    //string answer = findsubstring(str, patt);
    //vi answer = findanagrams(str, patt);
    //string answer = longestnonrepetitivesubstring(str);
    //string answer = longestsubstringwithKdisticnctcharacter(str);
    // string s ="ijfdghtrowordgoodbestwordjhgfsdripenebdu";
    // vs words = {"word","good","best","word"};
    // vi answer = findsubstring(s, words);
    //bool ans = checkinclusion(str, patt);
    // string str ="AABABBA";
    // int k=1;
    // string ans = longestsubstringafterKreplacement(str, k);







	return 0;
}
