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

// void heapify(int *arr, int n, int pos){
//     int largest = pos;
//     int l = 2*pos+1;
//     int r = 2*pos+2;
//     if((l<n)&& (arr[l]>arr[largest])){
//         largest = l;
//     }
//     if((r<n) &&(arr[r]>arr[largest])){
//         largest = r;
//     }
//     if(largest != pos){
//         swap(arr[largest], arr[pos]);
//         heapify(arr, n, largest);
//     }
// }
//
// void heapsort(int *arr, int n){
//     for(int i=n/2-1; i>=0; --i){
//         heapify(arr, n, i);
//     }
//     for(int i=n-1; i>0; --i){
//         swap(arr[i], arr[0]);
//         heapify(arr, i, 0);
//     }
// }

// void ssort(int *arr, int n, int k){
//     priority_queue<int, vi, greater<int>> pq(arr, arr+k+1);
//     int inx=0;
//     for(int i=k+1; i<n; ++i){
//         arr[inx++] = pq.top();
//         pq.pop();
//         pq.push(arr[i]);
//     }
//     while(!pq.empty()){
//         arr[inx++]=pq.top();
//         pq.pop();
//     }
// }
// void ssort(int *arr, int n, int k){
//     priority_queue<int, vi, greater<int>> pq(arr, arr+k+1);
//     int inx=0;
//     for(int i=k+1; i<n; ++i){
//         pq.push(arr[i]);
//         pq.pop();
//
//     }
//     while(!pq.empty()){
//         cout<<pq.top()<<" ";
//         pq.pop();
//     }
// }

// void countingsort(int *arr, int n){
//     int mx =-1;
//     for(int i=0; i<n; ++i){
//         if(arr[i]>mx){
//             mx = arr[i];
//         }
//     }
//     int output[n];
//     int count[mx+1];
//     for(int i=0; i<=mx; ++i){
//         count[i]=0;
//     }
//     for(int i=0; i<n; ++i){
//         ++count[arr[i]];
//     }
//     for(int i=1; i<=mx; ++i){
//         count[i] +=count[i-1];
//     }
//     for(int i=0; i<n; ++i){
//         output[count[arr[i]]-1] = arr[i];
//     }
//     for(int i=0; i<n; ++i){
//         arr[i]=output[i];
//     }
// }

// void cycleSort(int *arr, int n){
//     int cycle=0;
//     int pos=0;
//     int item; int writes=0;
//     for(cycle=0; cycle<=n-2; ++cycle){
//         item = arr[cycle];
//         for(int i=cycle+1; i<n; ++i){
//             if(arr[i]<item){
//                 pos +=1;
//             }
//         }
//         if(pos == cycle){
//             continue;
//         }
//         while(item == arr[pos]){
//             pos+=1;
//         }
//         if(pos !=cycle){
//             swap(arr[pos], item);
//             writes++;
//         }
//         while(pos != cycle){
//             pos = cycle;
//             for(int i=cycle+1; i<n; ++i){
//                 if(arr[i]<item){
//                     pos +=1;
//                 }
//             }
//             while(item == arr[pos]){
//                 pos+=1;
//             }
//             if(pos !=cycle){
//                 swap(arr[pos], item);
//                 writes++;
//             }
//         }
//     }
// }

// void cocktailsort(int *arr, int n){
//     bool swapped =true;
//     int start =0;
//      int end =n-1;
//      while(swapped){
//          swapped=false;
//          for(int i=start; i<end; ++i){
//
//              if(arr[i]>arr[i+1]){
//                  swap(arr[i], arr[i+1]);
//                  swapped=true;
//              }
//          }
//          if(!swapped){
//              break;
//          }
//          --end;
//          swapped = false;
//          for(int i=end-1; i>=start; --i){
//              if(arr[i] >arr[i+1]){
//                  swap(arr[i], arr[i+1]);
//                  swapped=true;
//              }
//          }
//          ++start;
//      }
// }

// void strandsort(list<int> &ip, list<int> &op){
//     if(ip.empty()){
//         return;
//     }
//     list<int> sublist;
//     sublist.pb(ip.front());
//     ip.pop_front();
//     for(auto it = ip.begin(); it != ip.end(); ){
//         if(*it>sublist.back()){
//             sublist.pb(*it);
//             it = ip.erase(it);
//         }else{
//             ++it;
//         }
//     }
//     op.merge(sublist);
//     strandsort(ip, op);
// }

// void countingsort(int *arr, int n ,int exp){
//     int output[n];
//     int i, count[10]={0};
//     for( i=0; i<n; ++i){
//         ++count[(arr[i]/exp)%10];
//     }
//     for( i=1; i<10; ++i){
//         count[i]+=count[i-1];
//     }
//     for(i = n-1; i>=0; --i){
//         output[count[(arr[i]/exp)%10]-1] = arr[i];
//         count[(arr[i]/exp)%10]--;
//     }
//     for (i = 0; i < n; i++) {
//         arr[i] = output[i];
//     }
// }
//
// void radixsort(int *arr, int n){
//     int mx =arr[0];
//     for(int i=1; i<n; ++i){
//         if(arr[i]>mx){
//             mx = arr[i];
//         }
//     }
//     for(int exp =1; mx/exp>0; exp *=10){
//         countingsort(arr, n, exp);
//     }
// }

// void bucketSort(float *arr, int n){
//     vector<float> b[n];
//     int bb;
//     for(int i=0; i<n; ++i){
//         bb = n*arr[i];
//         b[bb].pb(arr[i]);
//     }
//     for(int i=0; i<n; ++i){
//         sort(b[i].begin(), b[i].end());
//     }
//     int inx=0;
//     for(int i=0; i<n; ++i){
//         for(int j=0; j<b[i].size(); ++j){
//             arr[inx++]=b[i][j];
//         }
//     }
// }
//
// struct Node{
//     int data;
//     Node* left;
//     Node* right;
// };
// Node* addnode( int key){
//     Node* n = new Node;
//     n->data = key;
//     n->left = n->right = NULL;
//     return n;
// }
// Node* insert(Node* node, int key){
//     if(node == nullptr){
//         node = addnode(key);
//         return node;
//     }
//     if(key < node->data ){
//         node->left = insert(node->left, key);
//     }else if(key>node->data){
//         node->right = insert(node->right, key);
//     }
//     return node;
// }
// void inorder(Node* root, int *arr, int &pos){
//     if(root != NULL){
//         inorder(root->left, arr, pos);
//         arr[pos++]=root->data;
//         inorder(root->right, arr, pos);
//     }
// }
//
// void treesort(int *arr, int n){
//     Node* root = nullptr;
//     root = insert(root, arr[0]);
//     for(int i=1; i<n; ++i){
//         root = insert(root, arr[i]);
//     }
//     int pos=0;
//     inorder(root, arr, pos);
// }

// void shellsort(int *arr, int n){
//     int temp, j;
//     for(int gap=n/2; gap>0; gap=gap/2){
//         for(int i=gap; i<n; i+=1){
//             temp = arr[i];
//             for( j=i; j>=gap && arr[j-gap]>=temp; j-=gap){
//                 arr[j]=arr[j-gap];
//             }
//             arr[j]=temp;
//         }
//     }
// }

// int bsearch(int *arr, int temp, int l, int h){
//     if(l>=h){
//         if(temp>arr[l]){
//             return l+1;
//         }else{
//             return l;
//         }
//     }
//
//         int mid = l+(h-l)/2;
//         if(temp == arr[mid]){
//             return mid+1;
//         }
//         if(temp > arr[mid]){
//             return bsearch(arr, temp, mid+1, h);
//         }
//         return bsearch(arr, temp, l, mid-1);
//
//
// }
//
// void insertionsort(int *arr, int n){
//     int temp,j, pos, i;
//     for( i=1; i<n; ++i){
//         temp = arr[i];
//         j=i-1;
//         pos = bsearch(arr, temp, 0, j);
//         while(pos<=j){
//             arr[j+1]=arr[j];
//             j--;
//         }
//         arr[j+1]=temp;
//     }
// }
//
// void gnomesort(int *arr, int n){
//     int inx =0;
//      while(inx<n){
//          if(inx ==0){
//              inx++;
//          }
//          if(arr[inx]>=arr[inx-1]){
//              inx++;
//          }else{
//              swap(arr[inx], arr[inx-1]);
//              inx--;
//          }
//      }
//      return;
// }

// void combsort(int *arr, int n){
//     int gap=n;
//     bool swapped = true;
//     while(gap !=1 || swapped == false){
//         gap = (gap*10)/13;
//         if(gap<1){
//             gap=1;
//         }
//         swapped = false;
//         for(int i=0; i<n-gap; ++i){
//             if(arr[i]>arr[i+gap]){
//                 swap(arr[i], arr[i+gap]);
//                 swapped =true;
//             }
//         }
//     }
 // }
// void pigeonhole(int *arr, int n){
//     int mx= INT_MIN;
//     int mn = INT_MAX;
//     for(int i=0; i<n; ++i){
//         if(arr[i]>mx){
//         mx = arr[i];
//         }
//         if(arr[i]<mn){
//             mn = arr[i];
//         }
//     }
//     int range = mx-mn+1;
//     vi hole[range];
//     for(int i=0; i<n; ++i){
//         hole[arr[i]-mn].pb(arr[i]);
//     }
//     int inx=0;
//     for(int i=0; i<range; ++i){
//         for(auto it = hole[i].begin(); it != hole[i].end(); ++it){
//             arr[inx++]= *it;
//         }
//     }
// }

// void compare(int *arr, int i, int j, int dir){
//     if((arr[i]>arr[j]) == dir){
//         swap(arr[i], arr[j]);
//     }
// }
//
// void bitonicmerge(int *arr, int l, int cnt, int dir){
//     if(cnt>1){
//         int k=cnt/2;
//         for(int i=l; i<l+k; ++i){
//             compare(arr, i, i+k, dir);
//         }
//         bitonicmerge(arr, l, k, dir);
//         bitonicmerge(arr, l+k, k, dir);
//     }
// }
//
// void bitonicsort(int *arr, int l, int cnt, int dir){
//     if(cnt>1){
//         int k=cnt/2;
//         bitonicsort(arr, l, k, 1);
//         bitonicsort(arr, l+k, k, 0);
//         bitonicmerge(arr, l, cnt, dir);
//     }
// }


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    // //auto start = chrono::steady_clock::now();
	// code part
    //vector<int> arr = {-5, -10, 0, -3, 8, 5, -1, 10};
    //int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};

     // float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    // int s = (*(&arr + 1) - arr);
    // countsort(arr);
    //heapsort(arr, s);
    // bucketsort(arr, s);
    //radixsort(arr, s);
    //insertionsort(arr, s);
    //shellsort(arr, s);

    // for(int i =0; i<s; ++i){
    //     cout<<arr[i]<<"  ";
    // }
    // int arr[] = { 2, 6, 3, 12, 56, 8 };
    // int n = sizeof(arr)/sizeof(arr[0]);
    //int k=3;
    // heapsort(arr, n);
     //ssort(arr, n, k);

    // countingsort(arr, n);
    //cycleSort(arr, n);
    //cocktailsort(arr, n);
    // for(int i=0; i<n; ++i){
    //     cout<<arr[i]<<" ";
    // }
    // list<int> ip{10, 5, 30, 40, 2, 4, 9};
    // list<int> op;
    // strandsort(ip, op);
    // for(auto i : op){
    //     cout<<i<<" ";
    // }
    // int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // radixsort(arr, n);
    // for(int i=0; i<n; ++i){
    //     cout<<arr[i]<<" ";
    // }
    // float arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    // int n = sizeof(arr) / sizeof(arr[0]);
    // bucketSort(arr, n);
    // int arr[]= {3, 7, 4, 8, 6, 2, 1, 5};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // for(int i=0; i<n; ++i){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    //treesort(arr, n); //O(nlogn)
    //shellsort(arr, n);
    //insertionsort(arr, n);
    //gnomesort(arr, n);
    //combsort(arr, n);
    //pigeonhole(arr, n);
    //bitonicsort(arr, 0, n, 1);
    // for(int i=0; i<n; ++i){
    //     cout<<arr[i]<<" ";
    // }






	return 0;
}
