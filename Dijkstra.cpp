#include <bits/stdc++.h>
using namespace std;
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define ll long long
#define P  cout <<
#define S  cin >>
#define en  << endl
#define $  >>

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
                           // this method take O(v^2) complexity
void Dijkstra(int ** edges,int v, int s){
    bool * vis = new bool[v];
    int * dist = new int[v];

    for(int i=0;i<v;i++){
        vis[i]=false;
        dist[i]=INT_MAX;

    }
    dist[s]=0;
    for(int j=0;j<v;j++){
        int I = -1;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(dist[i]<dist[I] || I==-1){
                    I=i;
                }
            }
        }

        vis[I]=true;
        for(int i=0;i<v;i++){
            if(edges[I][i] and !vis[i]){
                if(edges[I][i]+dist[I]<dist[i]){
                    dist[i] = edges[I][i]+dist[I];
                }
            }
        }
    }

    for(int i=0;i<v;i++){
        cout  << dist[i] << " ";
    }
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


int main(){
fastread();
int v,e;cin>>v>>e;  // v : vertex, e : edges
int ** edges = new int*[v];
for(int i=0;i<v;i++){
    edges[i] = new int[v];
    for(int j=0;j<v;j++){
        edges[i][j]=0;
    }
}

for(int i=0;i<e;i++){
    int x,y,w;cin>>x>>y>>w; // x:first ,y:second node ,w: weight of x and y 
    edges[x][y]=w;
    edges[y][x]=w;
}


Dijkstra(edges,v,0);
return 0;
}