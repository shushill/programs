#include <bits/stdc++.h>
using namespace std;

#define sz size()
//#define beg begin()
//#define end end()
#define mod 1000000007
#define INF 0x3f3f3f3f
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

void countsort(char arr[]){
    int l = (*(&arr + 1) - arr);
    char out[l];
    int count[256];
    memset(count, 0, sizeof(count));
    for(int i=0; arr[i]; ++i){
        ++count[arr[i]];
    }
    for(int i =1; i<256; i++){
        count[i] += count[i-1];
    }
    for(int i = 0; arr[i]; ++i){
        out[count[arr[i]] -1 ] = arr[i];
        --count[arr[i]];
    }
    for(int i =0; arr[i]; i++){
        arr[i] = out[i];
    }
}

void bucketsort(float arr[], int s){
    vector<float> b[s];
    for(int i =0; i <s; ++i){
        int bi = s*arr[i];
        b[bi].pb(arr[i]);
    }
    for(int i =0; i <s; ++i){
        sort(b[i].begin(), b[i].end());
    }
    int index =0;
    for(int i =0; i<s; ++i){
        for(int j =0; j<b[i].size(); ++j){
            arr[index++] = b[i][j];
        }
    }
}

int findmax(int arr[], int s){
    int max = arr[0];
    for(int i =1; i < s; ++i){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void ccountsort(int arr[], int s, int exp){
    int out[s];
    int count[10] ={0};
    for(int i =0; i <s; ++i){
        count[(arr[i]/exp)%10]++;
    }
    for(int i =1; i <10; ++i){
        count[i] += count[i-1];
    }
    for(int i =s-1;  i>=0; --i){
        out[ count[(arr[i]/exp)%10] - 1] = arr[i];
        --count[(arr[i]/exp)%10];
    }
    for(int i =0; i < s; ++i ){
        arr[i] = out[i];
    }
}
void radixsort(int arr[], int s){
    int max = findmax(arr, s);
    for(int exp = 1; max/exp>0; exp *=10){
        ccountsort(arr, s, exp);
    }
}

void insertionsort(int arr[], int s){
    int i, j, key;
    for(i =1; i<s; ++i){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] =arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void shellsort(int arr[], int s){
    for(int gap = s/2; gap >0; gap /=2){
        for(int i = gap ; i <s; i +=1){
            int temp = arr[i];
            int j;
            for( j=i; j >=gap && arr[j - gap] > temp; j = j-gap ){
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}
void heapify(int arr[], int s, int i){
    int lg =i;
    int l = 2*i +1;
    int r = 2*i +2;
    if(l < s && arr[l] > arr[lg]){
        lg = l;
    }
    if(r <s && arr[r] > arr[lg]){
        lg = r;
    }
    if(lg != i){
        swap(arr[i], arr[lg]);
        heapify(arr, s, lg);
    }

}

void heapsort(int arr[], int s){
    for(int i = s/2 -1; i>=0; --i){
        heapify(arr, s, i);
    }
    for(int i = s-1; i>0; --i){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    // //auto start = chrono::steady_clock::now();
	// code part
    //vector<int> arr = {-5, -10, 0, -3, 8, 5, -1, 10};
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};

     // float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
     int s = (*(&arr + 1) - arr);
    // countsort(arr);
    heapsort(arr, s);
    // bucketsort(arr, s);
    //radixsort(arr, s);
    //insertionsort(arr, s);
    //shellsort(arr, s);

    for(int i =0; i<s; ++i){
        cout<<arr[i]<<"  ";
    }





	return 0;
}
