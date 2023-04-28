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
typedef vector<pii> vpii;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef map<string, int> msi;



namespace Graph{
    using namespace std;
    struct graph1{
        int V;
        vpii *adj;
    };
    graph1* creategraph(int V){
        graph1 *g = new graph1;
        g->V = V;
        g->adj = new vpii[V];
        return g;
    }
    void addEdge(graph1 *g, int src, int dest, int w){
        g->adj[src].pb(mp(dest, w));
        g->adj[dest].pb(mp(src, w));
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
    void dfs(int i, vi &vis, graph1 *g){
        if(!vis[i]){
            vis[i]=1;
            cout<<i<<" ";
            for(auto it = g->adj[i].begin(); it != g->adj[i].end(); ++it){
                dfs((*it).first, vis, g);
            }
        }
    }
    void dfstraversal(graph1 *g){
        vi vis(g->V, 0);
        for(int i=0; i<g->V; ++i){
            if(!vis[i]){
                dfs(i, vis, g);
            }
        }
    }
    void bfstraversal(graph1 *g, int src){
        cout<<endl;
        vi vis(g->V, 0);
        queue<int> q;
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int k = q.front();q.pop();
            cout<<k<<" ";
            for(auto it = g->adj[k].begin(); it != g->adj[k].end(); ++it){
                if(!vis[(*it).first]){
                    q.push((*it).first);
                    vis[(*it).first] =1;
                }
            }
        }
    }
    
    void fillorder(int i, stack<int> &s, vi &vis, graph1* g){
        vis[i]=1;
        for(auto it = g->adj[i].begin(); it !=g->adj[i].end(); ++it ){
            if(!vis[(*it).first]){
                fillorder((*it).first, s, vis, g);
            }
        }
        s.push(i);
    }
    graph1* createtranspose(graph1 *g){
        graph1 *gg = new graph1;
        gg->V = g->V;
        gg->adj = new vpii[g->V];
        // for(int i=0; i < g->V; ++i){
        //     gg->adj[i] = g->adj[i];
        // }
        for(int v=0; v < g->V; ++v){
            for(auto it = g->adj[v].begin(); it != g->adj[v].end(); ++it){
                gg->adj[(*it).first].pb(mp(v, (*it).second));
            }
        }
        // cout<<"\nNew graph"<<endl;
        //this solution is for this graph
        // Graph::addEdge(g, 1, 0, 4);
        // Graph::addEdge(g, 0, 2, 8);
        // Graph::addEdge(g, 2, 1, 8);
        // Graph::addEdge(g, 0, 3, 11);
        // Graph::addEdge(g, 3, 4, 7);
        // printgraph(gg);
        return gg;

    }
    void printSCC(graph1 *g){
        vi vis(g->V, 0);
        stack<int> s;
        for(int i=0; i<g->V; ++i){
            if(!vis[i]){
                fillorder(i, s, vis, g);
            }
        }
        graph1 *g2 = createtranspose(g);
        fill(vis.begin(), vis.end(), 0);
        while(!s.empty()){
            int vt = s.top();
            s.pop();
            if(!vis[vt]){
                dfs(vt, vis, g2);
                cout<<endl;
            }
        }

    }
    void findmothervertex(graph1 *g){
        cout<<endl;
        vi vis(g->V, 0);
        int m;
        for(int i=0; i<g->V; ++i){
            if(!vis[i]){
                dfs(i, vis, g);
                 m = i;
            }
        }
        fill(vis.begin(), vis.end(), 0);
        dfs(m, vis, g);
        for(int i=0; i< g->V; ++i){
            if(vis[i]==0){
                cout<<"Mother vertex not present"<<endl;
                return;
            }
        }
        cout<<"Mother vertex is "<<m<<endl;
    }
    void floydmarshall(){

        int V=9;
        int graph[V][V] = {
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

        int dist[V][V];
        int i,j,k;
        for( i=0; i<V; ++i){
            for( j=0; j <V; ++j){
                dist[i][j] = graph[i][j];
            }
        }
        for( k=0; k <V; ++k){
            for( i=0; i<V; ++i){
                for( j=0; j<V; ++j){
                    dist[i][j] = dist[i][j] || (dist[i][k] && dist[k][j]);
                }
            }
        }
        for(int i=0; i<V; ++i){
            for(int j=0; j <V; ++j){
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    bool DFSUtil(int i, vi& visited, vi &vDegree, int k, graph1 *g){
        visited[i] = 1;
        for(auto it = g->adj[i].begin(); it != g->adj[i].end(); it++ ){
            if(vDegree[i] < k){
                vDegree[(*it).first]--;
            }
            if(!visited[(*it).first]){
                if(DFSUtil((*it).first, visited, vDegree, k, g)){
                    vDegree[i]--;
                }
            }
        }
        if(vDegree[i]<k){
            return true;
        }
        return false;
    }

    void kcoresgraph(int k, graph1 *g){
        vi visited(g->V, 0);
        int mindeg = INF;
        vi vDegree(g->V);
        int startvertex;
        for(int i=0; i<g->V; ++i){
            vDegree[i] = g->adj[i].size();
            if(vDegree[i]<mindeg){
                mindeg = vDegree[i];
                startvertex =i;
            }
        }
        DFSUtil(startvertex, visited, vDegree, k, g);
        for(int i=0; i<g->V; ++i){
            if(!visited[i]){
                DFSUtil(i, visited, vDegree, k, g);
            }
        }
        cout<<"K cores"<<endl;
        for(int i=0; i<g->V; ++i){
            if(vDegree[i] >= k){
                cout<<"["<<i<<"]";
                for(auto it = g->adj[i].begin(); it != g->adj[i].end(); ++it){
                    if(vDegree[(*it).first]>=k){
                        cout<<"-->"<<"("<<(*it).first<<")";
                    }
                }
                cout<<endl;
            }
        }
    }
    void iterativeDFS(int src, graph1 *g){
        vi visited(g->V, 0);
        stack<int> st;
        st.push(src);
        int s;
        while(!st.empty()){
            s = st.top();
            st.pop();
            if(!visited[s]){
                cout<<s<<" ";
                visited[s] = 1;
            }
            for(auto it = g->adj[s].begin(); it != g->adj[s].end(); ++it){
                if(!visited[(*it).first]){
                    st.push((*it).first);
                }
            }
        }
    }
    void levelOrderTraversal(graph1 *g, int l, int src){
        vi visited(g->V, 0);
        mii level;
        queue<int> q;
        q.push(src);
        visited[src]=1;
        level[src]=0;
        int x;
        while(!q.empty()){
            x = q.front(); q.pop();
            for(auto it = g->adj[x].begin(); it != g->adj[x].end(); ++it){
                if(!visited[(*it).first]){
                    q.push((*it).first);
                    visited[(*it).first] = 1;
                    level[(*it).first] = level[x]+1;
                }
            }
        }
        for(auto it = level.begin(); it != level.end(); ++it){
            cout<<(*it).first<<"  "<<(*it).second<<endl;
        }
    }
    void countpathUtil(graph1 *g, int src, int dest, int &count){
        if(src == dest){
            count++;
            return;
        }
        for(auto it = g->adj[src].begin(); it != g->adj[src].end(); ++it){
            countpathUtil(g, (*it).first, dest, count);
        }
    }

    void pathcount(graph1 *g, int src, int dest){
        int count=0;
        countpathUtil(g, src, dest, count);
        cout<<"paths are "<<count<<endl;
    }

    void bfscolour(graph1 *g, vs &colour, vi &dist, vi &parent, int i){
        queue<int> q;
        q.push(i);
        dist[i]=0;
        colour[i] = "green";
        while(!q.empty()){
            int u = q.front(); q.pop();
            cout<<u<<" ";
            for(auto it = g->adj[u].begin(); it != g->adj[u].end(); ++it){
                if(colour[(*it).first]=="white"){
                    dist[(*it).first] = dist[u] +1;
                    parent[(*it).first] = u;
                    q.push((*it).first);
                    colour[(*it).first]="green";
                }
            }
            colour[u] = "dark green";
        }
    }

    void BFSfullcolour(graph1 *g){
        vs colour(g->V, "white");
        vi dist(g->V, 0);
        vi parent(g->V, -1);
        for(int i=0; i<g->V; ++i){
            if(colour[i]== "white"){
                bfscolour(g, colour, dist, parent, i);
            }
        }
        cout<<endl;
        for(int i=0; i<g->V; ++i){
            cout<<i<<"  "<<colour[i]<<" "<<dist[i]<<" "<<parent[i]<<endl;
        }
    }
}






int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//code part
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
    int V=9;
    Graph::graph1 *g = Graph::creategraph(V);
    Graph::addEdge(g, 0, 1, 4);
    Graph::addEdge(g, 0, 7, 8);
    Graph::addEdge(g, 1, 2, 8);
    Graph::addEdge(g, 1, 7, 11);
    Graph::addEdge(g, 2, 3, 7);
    Graph::addEdge(g, 2, 8, 2);
    Graph::addEdge(g, 2, 5, 4);
    Graph::addEdge(g, 3, 4, 9);
    Graph::addEdge(g, 3, 5, 14);
    Graph::addEdge(g, 4, 5, 10);
    Graph::addEdge(g, 5, 6, 2);
    Graph::addEdge(g, 6, 7, 1);
    Graph::addEdge(g, 6, 8, 6);
    Graph::addEdge(g, 7, 8, 7);



    //matrix


    Graph::printgraph(g);
    // Graph::dfstraversal(g);
    // Graph::bfstraversal(g, 0);
    //Graph::printSCC(g);
    //Graph::findmothervertex(g);
    //Graph::kcoresgraph(3, g);
    //Graph::iterativeDFS(0, g);
    //Graph::levelOrderTraversal(g, 2, 0);
    //Graph::pathcount(g, 0, 4); //ifinite loop in a cycle graph O(!N)
    //Graph::BFSfullcolour(g);










	return 0;
}
