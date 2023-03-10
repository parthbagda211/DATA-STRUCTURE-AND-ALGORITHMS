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
#define vii vector<vector<int>>
#define ff first
#define ss second
#define pb push_back
#define $  >>
#define MAX 1000
int cost=0;
int parent[MAX],size[MAX];

//*********************************************************************************************
// Sort all the edges in the graph in non-decreasing order of their weight.
// Create an empty minimum spanning tree.
// Loop through all the edges in the sorted order. For each edge:
// Check if adding the edge will create a cycle in the minimum spanning tree.
// If not, add the edge to the minimum spanning tree.
// If yes, discard the edge.
// Stop when all the vertices are connected or all edges have been processed.



//The time complexity of Kruskal's algorithm is O(E log E) using a union-find data structure to efficiently detect cycles.
// Here, E is the number of edges in the graph. The space complexity is O(E) for storing the edges and the minimum spanning tree.

//*********************************************************************************************
int find(int v){
    if(parent[v]==v) return v;
    return find(parent[v]);
}
void merge(int u,int v){
    u = find(u),v=find(v);
    if(size[u]<size[v]) swap(u,v);
    parent[v]=u;
    size[u]+=size[v];
}
void kruskal(vii&vt,int v,vii&ans){
    sort(all(vt));
    for(int i=0;i<v;i++){
        parent[i]=i;
        size[i]=1;

    }
    int count=0;
    

    for(auto it : vt){
        int w=it[0],x=it[1],y=it[2];

       if(find(x)!=find(y)){
              
        ans.pb({x,y,w});
        
         merge(x,y);
        cost+=w;
        count++;
        if(count==v-1) break; // yes, cycle is present
        }
       
    }
}
int main(){
fastread();
int v,e;cin>>v>>e;
vii vt;
FOR(i,0,e){
    int x,y,w;cin>>x>>y>>w;
    vt.pb({w,x,y});
    vt.pb({w,y,x});

}
vii ans;
kruskal(vt,v,ans);
for(auto it : ans){
    for(auto i : it){
        cout << i << " ";
    }
    cout << endl;
}
cout << endl;
cout << cost << endl;
return 0;
}