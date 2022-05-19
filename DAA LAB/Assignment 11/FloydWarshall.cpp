#include<bits/stdc++.h>
using namespace :: std;

vector<vector<int> > floyd_warshall(vector<vector<int> > graph){
    vector<vector<int> > dist(graph);
    int v=graph.size();

    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][j]>(dist[i][k]+dist[k][j])){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    return dist;
}

int main(){
    vector<vector<int> > graph={{0, INT_MAX, -2, INT_MAX},{4, 0, 3, INT_MAX},{INT_MAX, INT_MAX, 0, 2},{INT_MAX, -1, INT_MAX, 0}};
    vector<vector<int> > ans = floyd_warshall(graph);


    cout<<"Shortest Distance Matrix for the given graph: \n";
    for(auto i: ans){
        for(int j=0; j<graph.size(); j++){
            cout<<i[j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}