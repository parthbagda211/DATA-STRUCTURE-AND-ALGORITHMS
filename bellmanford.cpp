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
//************************************************************************************************************
// Initialize distances to all nodes as infinity except the source node, which is set to 0.
// Loop through all nodes for (V-1) times, where V is the number of vertices in the graph. For each iteration:
// Loop through all edges and update the distance to the adjacent node if it can be improved by going through the current node.
// Check for negative weight cycles by looping through all edges one more time.
//  If any distance can be further improved, it indicates the presence of a negative weight cycle.


// The time complexity of the Bellman-Ford algorithm is O(VE), where V is the number of vertices and E is the number of edges in the graph. 
// The space complexity is O(V) for storing the distances to all nodes.
//**************************************************************************************************************
void bellmanford(vii&vt,int v , int src){
    vi dist(v,INT_MAX);
    dist[src]=0;

    FOR(i,0,v-1){
        for(auto it : vt){
            int x = it[0];
            int y = it[1];
            int w = it[2];

            if(dist[x]!=INT_MAX and dist[x]+w<dist[y]){
                dist[y] = dist[x]+w;
            }
        }
    }
    FOR(i,0,v){
        cout << dist[i] << " ";
    }
}
int main(){
fastread();
int v,e;cin>>v>>e;
int **g = new int*[v];
FOR(i,0,v){
    g[i] = new int[v];
    FOR(j,0,v){
        g[i][j]=0;
    }
}
FOR(i,0,e){
    int x,y,z;cin>>x>>y>>z;
    g[x][y]=z;
    g[y][x]=z;

}
vii vt;
// FOR(i,0,e){
//     int x,y,w;cin>>x>>y>>w;
//     vt.pb({x,y,w});
//     vt.pb({y,x,w});
// }
FOR(i,0,v){
    FOR(j,0,v){
        if(g[i][j]!=0){
            vt.pb({i,j,g[i][j]});
           vt.pb({j,i,g[i][j]});
        }
    }
}

bellmanford(vt,v,0);
return 0;
}