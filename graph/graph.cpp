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
typedef vector<pii> vpii;
typedef set<pii> spii;
typedef set<int> si;
typedef map<string, int> msi;


#define VV 9

namespace Graphh{
    using namespace std;
    struct graph1{
        int V;
        set<pii> *adj;
    };
    graph1* creategraph(int V){
        graph1 *g = new graph1;
        g->V = V;
        g->adj = new set<pii>[V];
        return g;
    }
    void addEdge(graph1 *g, int src, int dest, int w){
        g->adj[src].insert(mp(dest, w));
        g->adj[dest].insert(mp(src, w));
    }
    void printgraph(graph1 *g){
        for(int v=0; v<g->V; ++v){
            cout<<"["<<v<<"]";
            for(auto it = g->adj[v].begin(); it != g->adj[v].end(); ++it){
                cout<<"-->"<<"("<<(*it).first<<","<<(*it).second<<")";
            }
            cout<<endl;
        }
    }
}
namespace Graphhh{
    using namespace std;
    struct graph1{
        int V;
        unordered_map<int, int> *adj;
    };
    graph1* creategraph(int V){
        graph1 *g = new graph1;
        g->V = V;
        g->adj = new unordered_map<int, int>[V];
        return g;
    }
    void addEdge(graph1 *g, int src, int dest, int w){
        g->adj[src].insert(mp(dest, w));
        g->adj[dest].insert(mp(src, w));
    }
    void printgraph(graph1 *g){
        for(int v=0; v< g->V; ++v){
            cout<<"["<<v<<"]";
            for(auto it = g->adj[v].begin(); it != g->adj[v].end(); ++it){
                cout<<"-->"<<"("<<(*it).first<<","<<(*it).second<<")";
                //cout<<"-->"<<"("<<(*it)<<")";
            }
            cout<<endl;
        }
    }
}


class Graph{
    int V;
    vpii *adj;

    array<int, N> vis;

  public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPathPQ(int src);
    void shortestPathSet(int src);
    void listPrint();
    void dfstraversal();
    void dfs(int);
    void bfstraversal(int);
};

Graph::Graph(int V){
    this->V = V;
    adj = new vpii[V];
}

void Graph::addEdge(int u, int v, int w){
    adj[u].pb(mp(v, w));
    adj[v].pb(mp(u, w));
}

void Graph::listPrint(){
    vpii::iterator it;
    for(int i = 0; i < V; ++i){
        cout<<"["<<i<<"]";
        for(it = adj[i].begin(); it != adj[i].end(); ++it){
            cout<<"-->"<<"("<<(*it).first<<","<<(*it).second<<")";
        }
        cout << endl;
    }
}

void Graph::dfs(int i){

   if(!vis[i]){       // for all vertices in each component
       vis[i] = 1;
       cout << i << " ";
       for(vpii::iterator it = adj[i].begin(); it != adj[i].end(); it++){
           int k = (*it).first;
           dfs(k);
       }
   }
}

void Graph::dfstraversal(){
    fill(vis.begin(), vis.end(), 0);

    for(int i =0; i < V; i++){ // for all components or vertices
        if(!vis[i]){
            dfs(i);
        }
    }
}

void Graph::bfstraversal(int source){
    fill(vis.begin(), vis.end(), 0);
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while(!q.empty()){
        int k = q.front(); q.pop();
        cout << k << " ";
        for( vpii::iterator it = adj[k].begin(); it != adj[k].end(); ++it){
            if(!vis[(*it).first]){
                q.push((*it).first);
                vis[(*it).first] = 1;
            }
        }
    }
}

void Graph::shortestPathPQ(int src){
    priority_queue<pii, vpii, greater<pii> > pq;
    vi dist(V, INF);
    pq.push(mp(0, src));
    dist[src] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        vpii::iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); ++i){
            int vt = (*i).first;
            int w = (*i).second;
            if(dist[vt] > dist[u] + w){
                dist[vt] = dist[u] + w;
                pq.push(mp(dist[vt], vt));
            }
        }
    }
    cout <<"Vertex distance from source: "<<endl;
    for(int i = 0; i < V; ++i){
        cout << i <<"\t\t"<<dist[i]<<endl;
    }
}

void Graph::shortestPathSet(int src){
    spii setds;
    vi dist(V, INF);
    setds.insert(mp(0, src));
    dist[src]=0;
    while(!setds.empty()){
        pii temp = *(setds.begin());
        setds.erase(setds.begin());
        int u = temp.second;
        vpii::iterator i;
        for(i=adj[u].begin(); i != adj[u].end();++i){
            int v = (*i).first;
            int w = (*i).second;
            if(dist[v] > dist[u] + w){
                if(dist[v]!=INF){
                    setds.erase(setds.find(mp(dist[v], v)));
                }
                dist[v] = dist[u] +w;
                setds.insert(mp(dist[v], v));
            }
        }
    }
    cout <<"Vertex distance from source: "<<endl;
    for(int i = 0; i < V; ++i){
        cout << i <<"\t\t"<<dist[i]<<endl;
    }
}
int mindistance(vi dist, vb sptSet){
    int min = INF, min_inx;
    for(int v=0; v<VV; ++v){
        if(sptSet[v]==false && dist[v] <= min){
            min = dist[v];
            min_inx = v;
        }
    }
    return min_inx;
}


void shortestpathformatrix(int graph[VV][VV], int src){
    vi dist(VV, INF);
    vb sptSet(VV, false);
    dist[src] =0;
    for(int count=0; count<VV-1; count++){
        int u = mindistance(dist, sptSet);
        sptSet[u]= true;
        for(int v=0; v<VV; ++v){
            if(!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout <<"Vertex distance from source: "<<endl;
    for(int i = 0; i < VV; ++i){
        cout << i <<"\t\t"<<dist[i]<<endl;
    }
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    //code part
    //solve here
    int V =9;
    Graph g(V);
    //
    //          8     7             0--->1    0--->7
    //       1----2-------3         1--->2    1--->7
    //      /     |\      |\        2--->3    2--->5  2--->8
    //    4/    2 | \     | \9      3--->4    3--->5
    //    /       |  \  14|  \      4--->5
    //   0        8   \   |   4     5--->6
    //    \      / \  4\  |  /      6--->8    6--->7
    //   8 \   7/  6\   \ | /10     7--->8
    //      \  /     \   \|/
    //       7-------6----5
    //           1     2
    //

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    //matrix
    int graph[VV][VV] = {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };



    //g.listPrint();

    //g.dfstraversal();
    //g.bfstraversal(0);

    //g.shortestPathPQ(0);
    //g.shortestPathSet(0);
    //shortestpathformatrix(graph, 0);


    int a =9, b =7, d = 8;
    int c = a || (b && d);
    cout<<c<<endl;


	return 0;
}
