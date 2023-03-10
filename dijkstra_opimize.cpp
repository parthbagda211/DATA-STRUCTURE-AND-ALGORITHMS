#include <bits/stdc++.h>
using namespace std;
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define ll long long
#define P  cout <<
#define S  cin >>
#define en  << endl
#define $  >>
#define pii pair<int,int>
int INF = 1e9;
//*************************************************************************************************
// Initialize distances to all nodes as infinity except the source node, which is set to 0.
// Create a priority queue of all nodes and their distances from the source node.
// Loop through the priority queue until all nodes have been processed or the destination node is reached. For each node:
// Get the node with the shortest distance from the priority queue.
// Loop through all adjacent nodes and update their distances if they can be improved by going through the current node.
// Update the priority queue with the new distances.
// Stop when all nodes have been processed or the destination node is reached.


// The time complexity of Dijkstra's algorithm is O((V+E)logV),
//  where V is the number of vertices and E is the number of edges in the graph, using a binary heap as the priority queue. 
//  The space complexity is O(V+E) for storing the distances and adjacency list.


//*******************************************************************************************************
void dijkstra(vector<vector<pii>>&graph,int v, int src){
vector<int>dist(v,INF);
vector<bool>vis(v,false);
priority_queue< pii,vector<pii>,greater<pii> > pq;
dist[src]=0;
pq.push({0,src});
while(!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    if(vis[u]){
        continue;
    }
    vis[u]=true;

    for(auto it : graph[u]){
        int v = it.first;
        int w = it.second;

        if(!vis[v] and dist[u]+w<dist[v]){
            dist[v] = dist[u]+w;
            pq.push({dist[v],v});
        }
    }
}
for(int i=0;i<v;i++){
    cout << i << "->" << dist[i] << endl;
}
}
int main(){
fastread();
int v,e;cin>>v>>e;
int ** graph = new int*[v];
for(int i=0;i<v;i++){
    graph[i]=new int[v];
    for(int j=0;j<v;j++){
        graph[i][j]=0;
    }
}
for(int i=0;i<e;i++){
    int x,y,z;cin>>x>>y>>z;
    graph[x][y]=z;
    graph[y][x]=z;

}
vector<vector<pii>> vt(v);
for(int i=0;i<v;i++){
 for(int j=0;j<v;j++){
    if(graph[i][j]!=0){
        vt[i].push_back({j,graph[i][j]});
        vt[j].push_back({i,graph[i][j]});
    }
 }
}
dijkstra(vt,v,0);

return 0;
}