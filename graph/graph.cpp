#include "C++template.h"

class Graph{
    int V;
    vpii *adj;

    array<int, N> vis;

  public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int src);
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

void Graph::shortestPath(int src){
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
    cout <<"Vertex    distance from source: "<<endl;
    for(int i = 0; i < V; ++i){
        cout << i <<"\t\t"<<dist[i]<<endl;
    }

}


int main(int argc, char *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //solve here
    int V = 9;
    Graph g(V);

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

    g.listPrint();

    //g.dfstraversal();
    g.bfstraversal(0);

    //g.shortestPath(0);


	return 0;
}
