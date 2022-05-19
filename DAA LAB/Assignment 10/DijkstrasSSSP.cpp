#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int> > roads,int n)
{
    vector<pair<int, int> > l[n+1];
    for(auto i:roads){
        l[i[0]].push_back({i[1], i[2]});
        l[i[1]].push_back({i[0], i[2]});
    }
    
    vector<int> dist(n+1, INT_MAX);
    vector<int> par(n+1, -1);
    set<pair<int, int> > s;
    
    dist[1]=0;
    s.insert({0, 1});
    while(!s.empty()){
        auto it=s.begin();
        s.erase(it);
        int node = it->second;
        int nodeDist = it->first;
        
        for(auto i:l[node]){
            int nbr=i.first;
            int wt = i.second;
            
            if(dist[nbr]>(nodeDist+wt)){
                par[nbr]=node;
                
                auto f=s.find({dist[nbr], nbr});
                if(f!=s.end()){
                    s.erase(f);
                }
                dist[nbr]=nodeDist+wt;
                s.insert({dist[nbr], nbr});
            }
        }
    }
    
    // for(auto i:par){
    //     cout<<i<<" ";
    // }
    // cout<<"\n";
    stack<int> u;
    int d=n;
    while(par[d]!=-1){
        u.push(d);
        d=par[d];
    }
    u.push(1);
    
    vector<int> ans;
    while(!u.empty()){
        ans.push_back(u.top());
        u.pop();
    }
    
    return ans;
}

int main(){
    int n=5;
    vector<vector<int> > edges = {{1,2,2},{2,5,5},{2,3,4},{1,4,1},{4,3,3},{3,5,1}};
    vector<int> ans=shortestPath(edges, n);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}