#include <bits/stdc++.h>
using namespace std;

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
    node *left;
    node *right;
};
node* insert(node* Node, int key){
    if(Node == nullptr){
        node *temp = new node;
        temp->left = nullptr;
        temp->right = nullptr;
        temp->data = key;
        return temp;
    }
    if(key< Node->data){
        Node->left = insert(Node->left, key);
    }
    else if(key>Node->data){
        Node->right = insert(Node->right, key);
    }
    return Node;
}

void print(node *root){
    if(root){
        print(root->left);
        cout<<root->data<<"  ";
        print(root->right);
    }
}
int findmaxrec(node *root){
    int rval, left, right, max = INT_MIN;
    if(root == nullptr) return max;
        rval = root->data;
        left = findmaxrec(root->left);
        right = findmaxrec(root->right);
        if(left>right){
            max = left;
        }else{
            max = right;
        }
        if(rval>max){
            max = rval;
        }
        return max;
}
int findmaxiter(node* root){
    node* temp;
    int max = INT_MIN;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();q.pop();
        if(temp->data > max) max = temp->data;
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return max;
}


void addelement(node** root){
    *root = insert(*root, 50);
    insert(*root, 30);  /*                    50            */
    insert(*root, 20);  /*                  /    \          */
    insert(*root, 40);  /*                 30     70        */
    insert(*root, 70);  /*                /  \    /  \      */
    insert(*root, 60);  /*               20  40  60   80    */
    insert(*root, 80);
}

void insertIntoTree(node **root, int key){
    node *temp;
    node* newnode = new node;
    newnode->data = key;
    newnode->left = newnode->right = nullptr;
    if(!*root){
        *root = newnode;
        return;
    }else{
        queue<node*> q;
        q.push(*root);
        while(!q.empty()){
            temp = q.front(); q.pop();
            if(temp->left){
                q.push(temp->left);
            }else{
                temp->left = newnode;
                return;
            }
            if(temp->right){
                q.push(temp->right);
            }else{
                temp->right = newnode;
                return;
            }
        }
    }
}

int findelementrec(node* root, int key){
    int tmp=0;
    if(root){
        int d = root->data;
        if(d == key) return 1;
        else{
            tmp = findelementrec(root->left, key);
            if(!tmp){
                tmp = findelementrec(root->right, key);
            }
        }
    }
    return tmp;
}

int findelementiter(node *root, int key){
    node* temp; int t=0;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();q.pop();
        t = temp->data;
        if(t == key){
            return 1;
        }
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return 0;
}
int sizeOfTree(node* root){
    if(!root) return 0;
    else{
        int size = sizeOfTree(root->left) + sizeOfTree(root->right) +1;
        return size;
    }
}
int sizeOfTreeIter(node *root){
    int count = 0;
    if(!root) return count;
    else{
        queue<node*> q;
        q.push(root);
        node* temp;
        while(!q.empty()){
            temp = q.front(); q.pop();
            ++count;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return count;
}

void levelOrderReverseTraversal(node *root){
    if(!root) return;
    stack<node*> s; queue<node*> q;
    node* temp;
    q.push(root);
    while(!q.empty()){
        temp = q.front(); q.pop();
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
        s.push(temp);
    }
    while(!s.empty()){
        temp = s.top();
        int d = temp->data;
        cout<<d<<" ";
        s.pop();
    }
    cout<<endl;
}
void deleteTree(node *root){

    if(root){
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    }
}
void preorderIterative(node* root){
    stack<node*> s;
    while(1){
        while(root){
            cout<<root->data<<" ";
            s.push(root);
            root = root->left;
        }
        if(!s.empty()){
             root = s.top();s.pop();
             root = root->right;
        }else{
            break;
        }

    }
}

void inorderIterative(node* root){
    stack<node*> s;
    while(true){
        while(root){
            s.push(root);
            root = root->left;
        }
        if(!s.empty()){
            root = s.top();s.pop();
            cout<<root->data<<"  ";
            root = root->right;
        }else{
            break;
        }
    }
}

void postorderRecur(node* root){
    if(root){
        postorderRecur(root->left);
        postorderRecur(root->right);
        cout<<root->data<<"  ";
    }
}

void postorderIterative(node* root){
    stack<node*> s;
    node* prev = nullptr;
    do{
        while(root){
            s.push(root);
            root = root->left;
        }
        while(root == nullptr and !s.empty()){
            root = s.top();
            if(root->right == nullptr or root->right == prev){
                cout<<root->data<<"  ";
                s.pop();
                prev = root;
                root = nullptr;
            }else{
                root = root->right;
            }
        }
    }while(!s.empty());
}

int heightOfTree(node* root){
    int leftheight, rightheight;
    if(root){
        leftheight = heightOfTree(root->left);
        rightheight = heightOfTree(root->right);
        if(leftheight>rightheight){
            return (1 + leftheight);
        }else{
            return (1+ rightheight);
        }
    }
    return 0;
}

int heightofTreeIter(node* root){
    int level=0;
    queue<node*> q;
    if(!root) return 0;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front(); q.pop();
        if(temp == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
            ++level;
        }else{
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return level;
}

node* deepestNode(node* root){
    node* temp;
    queue<node*> q;
    if(!root) return nullptr;
    q.push(root);
    while(!q.empty()){
        temp = q.front(); q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return temp;
}

int numberofleaves(node* root){
    int count =0;
    queue<node*> q;
    if(!root) return 0;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front(); q.pop();
        if(temp->left == nullptr && temp->right == nullptr){
            ++count;
        }
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return count;
}

int numberofFullnode(node* root){
    int count=0;
    if(!root) return 0;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front(); q.pop();
        if(temp->left && temp->right){
            ++count;
        }
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return count;
}

int numberofnodeofonechild(node* root){
    node* temp;
    int count=0;
    if(!root) return 0;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front(); q.pop();
        if(!temp->left && temp->right || temp->right && !temp->left){
            ++count;
        }
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return count;
}

bool structurallyidentical(node* root, node* root1){
    if(root == nullptr && root1 == nullptr){
        return true;
    }
    if(root==nullptr || root==nullptr){
        return false;
    }
    return (root->data == root1->data && structurallyidentical(root->left, root1->left) && structurallyidentical(root->right, root1->right));
}

int search(int *inorder, int x, int n){
    for(int i=0; i<n; ++i){
        if(inorder[i] == x){
            return i;
        }
    }
    return -1;
}

void printpostoder(int *inorder, int *preorder, int n){

    int root = search(inorder, preorder[0], n);
    if(root !=0){
        printpostoder(inorder, preorder+1, root);
    }
    if(root !=n-1){
        printpostoder(inorder+root+1, preorder+root+1, n-root-1);
    }
    cout<<preorder[0]<<" ";
}

void postorderusingTwostack(node* root){
    if(root == nullptr){
        return;
    }
    stack<node*> s1, s2;
    s1.push(root);
    node* n;
    while(!s1.empty()){
        n = s1.top();
        s1.pop();
        s2.push(n);
        if(n->left){
            s1.push(n->left);
        }
        if(n->right){
            s1.push(n->right);
        }
    }
    while(!s2.empty()){
        n = s2.top();
        s2.pop();
        cout<<n->data<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // tree diagram
      /*                    50                      */
      /*                  /    \                    */
      /*                 30     70                  */
      /*                /  \    /  \                */
      /*               20  40  60   80              */

    //code part
    node *root = nullptr;
    node *root1 = nullptr;
    addelement(&root1);
    addelement(&root);
    //print(root1);cout<<endl;
    //preorderIterative(root);
    //inorderIterative(root);
    postorderRecur(root);cout<<endl;
    //postorderIterative(root);
    //int max = findmaxrec(root); //T=O(n) S=O(n)
    //int max = findmaxiter(root); //T=O(n) S=O(n)
    //int found = findelementrec(root, 10); //T=O(n) S=(n)
    //int found = findelementiter(root, 10); //T=O(n) S=(n)
    //insertIntoTree(&root, 10); //T=O(n) S=O(n)
    //int size = sizeOfTree(root); //T=O(n) S=O(n)
    //int size = sizeOfTreeIter(root); //T=O(n) S=O(n)
    //levelOrderReverseTraversal(root);  //T=O(n) S=O(n)
    //deleteTree(root); //T=O(n) S=O(n)
    //int height = heightOfTree(root);  //T=O(n) S=O(n) depth == height
    //int height = heightofTreeIter(root);
    //node* deep = deepestNode(root);
    //int leaves = numberofleaves(root);
    //int fullnode = numberofFullnode(root);
    //int halfNode = numberofnodeofonechild(root);
    //bool same = structurallyidentical(root, root1);

    // int preorder[] = {50, 30, 20, 40, 70, 60, 80};
    // int inorder[] = {20, 30, 40, 50, 60, 70, 80};
    // int n = sizeof(preorder)/sizeof(preorder[0]);
    // cout<<"Postorder traversal "<<endl;
    // printpostoder(inorder, preorder, n);
    //postorderusingTwostack(root);









    return 0;
}
