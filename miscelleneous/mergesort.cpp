#include <bits/stdc++.h>
using namespace std;

#define sz size()
#define beg begin()
#define end end()
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
typedef vector<pii> vpii;
typedef set<pii> spii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef map<string, int> msi;

struct node{
    int data;
    node *next;
};


void push(node **headref, int key){
    node * temp = new node;
    temp->data = key;
    temp->next = nullptr;

    if(*headref == nullptr) *headref = temp;
    else{
        temp->next = *headref;
        *headref = temp;
    }
}

void print(node *head){
    while(head){
        cout<<head->data<<"  ";
        head = head->next;
    }
    cout<<endl;
}

int lengthoflist(node* head){
    int count =0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

node *sortedMerge(node* a, node* b){
    node* res;
    if(!a){
        res = b;
        return res;
    }else if(!b){
        res = a;
        return res;
    }
    if(a->data <= b->data){
        res = a;
        res->next = sortedMerge(a->next, b);
    }else{
        res = b;
        res->next = sortedMerge(a, b->next );
    }
    return res;
}

void frontsplit(node* source, node** frontref, node** backref ){
    node* slow = source;
    node* fast = source;
    int i =0;
    while(fast->next != nullptr){
        if(i==0){
            fast = fast->next;
            i=1;
        }
        else if(i==1){
            fast = fast->next;
            slow = slow->next;
            i=0;
        }
    }
    *frontref = source;
    *backref = slow->next;
    slow->next = nullptr;
}

void MergeSortRecur(node** headref){
    node* head = *headref;
    node* a = nullptr;
    node* b = nullptr;
    if(head == nullptr || head->next == nullptr) return;
    frontsplit(head, &a, &b);
    MergeSortRecur(&a);
    MergeSortRecur(&b);
    *headref = sortedMerge(a, b);
}
void merge(node** start1, node** end1, node** start2, node** end2){
    node* temp = nullptr;
    if((*start1)->data > (*start2)->data ){
        swap(*start1, *start2);
        swap(*end1, *end2);
    }
    node* astart = *start1;
    node* aend = *end1;
    node* bstart = *start2;
    node* bend = *end2;
    node* bendnext = (*end2)->next;
    while(astart != aend && bstart != bendnext){
        if(astart->next->data > bstart->data){
            node* temp = bstart->next;
            bstart->next = astart->next;
            astart->next = bstart;
            bstart = temp;
        }
        astart = astart->next;
    }
    if(astart == aend){
        astart->next = bstart;
    }else{
        *end2 = *end1;
    }
}



void MergeSortIter(node** head){
    if(!head ) return;
    node* start1 = nullptr;
    node* end1 = nullptr;
    node* start2 = nullptr;
    node* end2 = nullptr;
    node* prevend = nullptr;
    int l = lengthoflist(*head);
    int c=0;
    for(int gap =1; gap<l; gap = gap*2){
        start1 = *head;
        while(start1){
            bool isFirstIter = 0;
            if(start1 == *head){
                isFirstIter =1;
            }
             c = gap;
            end1 = start1;
            while(--c && end1->next){
                end1 = end1->next;
            }
             c = gap;
             start2 = end1->next;
             if (!start2)
                break;

            end2 = start2;
            while(--c && end2->next){
                end2 = end2->next;
            }
            node* temp = end2->next;
            merge(&start1, &end1, &start2, &end2);
            if(isFirstIter){
                *head = start1;
            }else{
                prevend->next = start1;
            }
            prevend = end2;
            start1 = temp;
        }
        prevend->next = start1;
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

    node *a = nullptr;
    push(&a, 20);
    push(&a, 90);
    push(&a, 30);
    push(&a, 40);
    push(&a, 80);
    push(&a, 10);
    push(&a, 70);
    print(a);
    cout<<"Number of nodes "<<lengthoflist(a)<<endl;

    // node *b = nullptr;
    // push(&b, 35);
    // push(&b, 25);
    // push(&b, 15);
    // push(&b, 5);
    // print(b);

//    MergeSortRecur( &a);
    //MergeSortIter(&a);


    print (a);








    //driving code ends here
    // auto ends = chrono::steady_clock::now();
    // auto it =chrono::duration_cast<chrono::nanoseconds>(ends- start).count();
    // cout<<it<<endl;
	return 0;
}
