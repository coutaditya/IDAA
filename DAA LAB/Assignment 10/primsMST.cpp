#include<bits/stdc++.h>
using namespace :: std;

class Graph{
    public:
        int v;
        vector<pair<int, int> > * l;

        Graph(int n){
            this->v=n;
            l=new vector<pair<int, int> > [n]; 
        }

        void addEdge(int a, int b, int w){
            l[a].push_back({b, w});
            l[b].push_back({a, w});
        }

        int primsMST(){
            priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > q;

            bool*vis= new bool [v]{false};

            int ans=0;
            q.push({0, 0});
            while(!q.empty()){
                int to=q.top().second;
                int w=q.top().first;
                q.pop();

                if(vis[to]){
                    continue;
                }

                ans+=w;
                vis[to]=true;

                for(auto i:l[to]){
                    if(!vis[i.first]){
                        q.push({i.second, i.first});
                    }
                }
            }
            return ans;
        }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(1, 3, 3);

    cout<<"MST = "<<g.primsMST();
    return 0;
}