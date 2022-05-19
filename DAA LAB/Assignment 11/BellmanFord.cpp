#include<bits/stdc++.h>
using namespace :: std;

vector<int> bellmanFord(int n, vector<vector<int> > edges, int src){
    vector<int> dist(n+1, INT_MAX);
    dist[src]=0;

    for(int i=0; i<n-1; i++){
        for(auto i: edges){
            int u=i[0];
            int v=i[1];
            int wt=i[2];

            if(dist[u]!=INT_MAX && dist[v]>(dist[u]+wt)){
                dist[v]=dist[u]+wt;
            }
        }
    }

    // negative edge cycle detection
    for(auto i:edges){
        int u=i[0];
        int v=i[1];
        int wt=i[2];

        if(dist[u]!=INT_MAX && dist[v]>(dist[u]+wt)){
            cout<<"Negative Edge Cycle Present";
            exit(0);
        }
    }

    return dist;
}

int main(){
    int n=0, m=0;
    cin>>n>>m;
    vector<vector<int> > edges;
    for(int i=0; i<m; i++){
        int u=0, v=0, wt=0;
        cin>>u>>v>>wt;
        edges.push_back({u, v, wt});
    }
    vector<int> dist = bellmanFord(n, edges, 1);

    for(int i=1; i<n+1; i++){
        cout<<"node "<<i<<" is at a distance: "<<dist[i]<<"\n";
    }

    return 0;
}