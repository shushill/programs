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

void subset(vvi& finalset, vi& inputset, vi& ccomb, int sz, int cpos){
    if(cpos == sz){
        finalset.pb(ccomb);
        return;
    }
    subset(finalset,inputset, ccomb, sz, cpos+1);
    ccomb.pb(inputset[cpos]);
    subset(finalset, inputset, ccomb, sz, cpos+1);
    ccomb.pop_back();
}

void subsett(vvi& finalset, vi& inputset, vi& ccomb, int sz, int cpos){
    finalset.pb(ccomb);
    for(int i = cpos; i<sz; ++i){
        ccomb.pb(inputset[i]);
        subsett(finalset, inputset, ccomb, sz, i+1);
        ccomb.pop_back();
    }
}

vvi combinations(vi& inputset){
    vvi finalset;
    vi ccomb;
    int sz = inputset.size();
    //subset(finalset, inputset, ccomb, sz, 0);
    subsett(finalset, inputset, ccomb, sz, 0);
    return finalset;
}

vvi combination(vi &inputset){
    vvi finalset(1, vi());
    int n;
    for(int i =0; i<inputset.size(); ++i){

         n = finalset.size();
        for(int j =0; j <n;++j){
            finalset.pb(finalset[j]);
            finalset.back().pb(inputset[i]);
        }
    }
    return finalset;
}

void setsofsduplicates(vvi &finalset, vi& inputset, vi& temp, int sz, int cpos){
    finalset.pb(temp);
    for(int i = cpos; i<sz; ++i){
        if( i == cpos || inputset[i] != inputset[i-1]){
            temp.pb(inputset[i]);
            setsofsduplicates(finalset, inputset, temp, sz, i+1);
            temp.pop_back();
        }
    }
}

vvi subsetdupiter(vi &inputset){
    sort(inputset.begin(), inputset.end());
    vvi finalset(1, vi());
    int n;
    int start;
    for(int i =0; i<inputset.size(); ++i){
        start = (i>0 && (inputset[i] == inputset[i-1])) ? n : 0;
        n = finalset.size();
        for(int j =start; j< n; ++j){
            finalset.pb(finalset[j]);
            finalset.back().pb(inputset[i]);
        }
    }
    return finalset;
}


vvi subsetofduplicates(vi &inputset){
    vvi finalset;
    vi temp;
    int sz = inputset.size();
    setsofsduplicates(finalset, inputset, temp, sz, 0);
    return finalset;
}

vvi combinationITER(int n, int k){
    vvi finalset;
    int i =0;
    vi temp(k, 0);
    while(i>=0){
        temp[i]++;
        if(temp[i]>n){
            i--;
        }else if(i == k-1){
            finalset.pb(temp);
        }else{
            i++;
            temp[i] = temp[i-1];
        }
    }
    return finalset;
}


void subsetofk(int n, int k, int start, vvi& finalset, vi& temp){
    if(k==0){
        finalset.pb(temp);
        return;
    }
    for(int i = start; i + k-1<=n; ++i){
        temp.pb(i);
        subsetofk(n, k-1, i+1, finalset, temp);
        temp.pop_back();
    }
}

vvi combinationArrayRecur(int n,  int k){
    vvi finalset;
    vi temp;
    int start = 1;
    subsetofk(n, k, start, finalset, temp);
    return finalset;
}

void permute(vvi &finalset, vi &inputset, int start){
    if(start == inputset.size()){
        finalset.pb(inputset);
        return;
    }
    for(int i = start; i <inputset.size(); ++i){
        swap(inputset[start], inputset[i]);
        permute(finalset, inputset, start+1);
        swap(inputset[start], inputset[i]);
    }
}


vvi permtation(vi &inputset){
    vvi finalset;
    permute(finalset, inputset, 0);
    return finalset;
}

vvi permutte(vi &inputset){
    vvi finalset;
    sort(inputset.begin(), inputset.end());
    do{
        finalset.pb(inputset);
    }while(next_permutation(inputset.begin(), inputset.end()));
    return finalset;
}

void permuteheap(vvi &finalset, vi &inputset, int size){
    if(size == 1){
        finalset.pb(inputset);
        return;
    }
    for (size_t i = 0; i < size; i++){
        permuteheap(finalset, inputset, size -1);
        if(size%2 == 1){
            swap(inputset[0], inputset[size-1]);
        }else{
            swap(inputset[i], inputset[size-1]);
        }
    }
}


vvi getpermutationheap(vi &inputset){
    vvi finalset;
    int n = inputset.size();
    sort(inputset.begin(), inputset.end());
    permuteheap(finalset, inputset, n);
    return finalset;
}

void permutearray(vvi &finalset, vi& inputset, vi& temp, bool used[], int beg, int sz){
    if(temp.size() == sz){
        finalset.pb(temp);
        return;
    }
    for(int i =beg; i <sz; ++i){
        if(!used[i]){
            used[i] = true;
            temp.pb(inputset[i]);
            permutearray(finalset, inputset, temp, used, beg, sz);
            temp.pop_back();
            used[i] = false;
        }
    }
}

void permutearrayrepeated(vvi &finalset, vi& inputset, vi& temp, bool used[], int beg, int sz){
    if(temp.size() == sz){
        finalset.pb(temp);
        return;
    }
    char last = '\0';
    for(int i =beg; i <sz; ++i){
        if(!used[i]){
            if(inputset[i] != last){
            last = inputset[i];
            used[i] = true;
            temp.pb(inputset[i]);
            permutearrayrepeated(finalset, inputset, temp, used, beg, sz);
            temp.pop_back();
            used[i] = false;
            }
        }
    }
}

vvi getpermutearray(vi &inputset){
    vvi finalset;
    int n = inputset.size();
    vi temp;
    bool used[n];
    sort(inputset.begin(), inputset.end());
    //permutearray(finalset, inputset, temp, used, 0, n);
    permutearrayrepeated(finalset, inputset, temp, used, 0, n);
    return finalset;
}

void getpermuteusingset(vvi &finalset, vi &inputset, int beg, int n){
    if(beg == n){
        finalset.pb(inputset);
        return;
    }
    unordered_set<int> set;
    for(int i = beg; i< inputset.size(); ++i){
        if(set.count(inputset[i])){
            continue;
        }
            set.insert(inputset[i]);
            swap(inputset[beg], inputset[i]);
            getpermuteusingset(finalset, inputset, beg+1, n);
            swap(inputset[beg], inputset[i]);

    }
}

vvi getpermutearray1(vi &inputset){
    vvi finalset;
    sort(inputset.begin(), inputset.end());
    int sz = inputset.size();
    getpermuteusingset(finalset, inputset, 0, sz);
    return finalset;
}

vi getnextpermute(vi& inputset){
    int len = inputset.size();
    int num1;
    int num2;
    for( num1 = len -2; num1>=0; num1--){
        if(inputset[num1] < inputset[num1+1]){
            break;
        }
    }
    if(num1 <0){
        reverse(inputset.begin(), inputset.end());
    }else{
        for(num2 = len-1; num2 > num1; num2-- ){
            if(inputset[num2] > inputset[num1]){
                break;
            }
        }
        swap(inputset[num1], inputset[num2]);
        reverse(inputset.begin()+num1 + 1, inputset.end());
    }
    return inputset;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //code part

    //combinations
    vi inputset;
    inputset.pb(3);
    inputset.pb(2);
    inputset.pb(8);
    inputset.pb(4);
    inputset.pb(1);

    int n = 5; int k =3;
    //vvi finalset = combinations(inputset);
    //vvi finalset = combination(inputset); //without duplicates
    //vvi finalset = subsetofduplicates(inputset);
    //vvi finalset = subsetdupiter(inputset);
    //vvi finalset = combinationITER(n, k);
    //vvi finalset = combinationArrayIter(inputset, k);
    //vvi finalset = combinationArrayRecur(n, k);
    //vvi finalset = permtation(inputset);
    //vvi finalset = permutte(inputset);
    //vvi finalset = getpermutationheap(inputset);
    //vvi finalset = getpermutearray(inputset);
    //vvi finalset = getpermutearray1(inputset);
    vi finalnum = getnextpermute(inputset);
    vi finalnum = getnextpermute(finalnum1);



    //print the sets
    // for(int i =0; i< finalset.size(); ++i){
    //     for(int j =0; j < finalset[i].size(); ++j){
    //         cout<<finalset[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i =0; i<finalnum.size(); ++i){
        cout<<finalnum[i];
    }



    return 0;
}
