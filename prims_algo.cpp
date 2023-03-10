#include <bits/stdc++.h>
using namespace std;
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define ll long long
#define P  cout <<
#define S  cin >>
#define en  << endl
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define vi vector<int>
#define ff first
#define ss second
#define pb push_back
#define $  >>
//*******************************************************************************************************
// Choose an arbitrary starting node and add it to the minimum spanning tree.
// Initialize a priority queue of all edges connected to the minimum spanning tree, with their weights as the priority.
// Loop through the priority queue until all nodes are connected or all edges have been processed. For each edge:
// Check if the edge connects to a node not yet in the minimum spanning tree.
// If yes, add the edge to the minimum spanning tree and add all its adjacent edges to the priority queue.
// If no, discard the edge.
// Stop when all the vertices are connected or all edges have been processed.


//The time complexity of Prim's algorithm is O(E log V) using a priority queue data structure to efficiently find the closest edge to the tree.
// Here, V is the number of vertices in the graph and E is the number of edges. The space complexity is O(E+V) for storing the edges, vertices, and the minimum spanning tree
//*******************************************************************************************************
void primsMst(vector<vector<pii>> & graph,int v,vector<pii>&ans){
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    vector<int> key(v,INT_MAX),parent(v,-1);// To store key values and parent vertices of vertices
    vector<bool>inmst(v,false);// To represent set of vertices included in MST

    int src=0;

    pq.push({0,src});
    key[src]=0;
    while(!pq.empty()){
        int u = pq.top().ss;
        pq.pop();
        inmst[u]=true;
        for(auto it : graph[u]){
            int y=it.ff,w=it.ss;
            if(inmst[y]==false and w<key[y]){
                key[y]=w;
                parent[y]=u;
                pq.push({key[y],y});
            }
        }
    }
    for(int i=1;i<v;i++){
        ans.pb({parent[i],i});
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
vector<pii> ans;
primsMst(vt,v,ans);
int sum=0;
for(auto it : ans){
sum+=graph[it.ff][it.ss];
}
cout << sum << endl; // minmum cost or minimum spamming trees

return 0;
}