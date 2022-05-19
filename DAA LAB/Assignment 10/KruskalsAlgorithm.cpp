#include<bits/stdc++.h>
using namespace :: std;

bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return a.second<b.second;
}

class Graph{
    public:
        int v;
        vector<pair<pair<int, int>, int> > l;

        Graph(int n){
            this->v=n;
        }

        void addEdge(int a, int b, int w){
            l.push_back({{a, b}, w});
        }

        int findSet(int i, int par[]){
            if(par[i]==-1) return i;

            return par[i] = findSet(par[i], par);
        }

        void unionSet(int i, int j, int par[], int rank[]){
            int p1 = findSet(i, par);
            int p2 = findSet(j, par);

            if(p1!=p2){
                if(rank[p1]>rank[p2]){
                    par[p2]=p1;
                    rank[p1]+=rank[p2];
                }
                else{
                    par[p1]=p2;
                    rank[p2]+=rank[p1];
                }
            }
        }

        int kruskalsMST(){
            sort(l.begin(), l.end(), comp);
            int par[v];
            int rank[v];
            for(int i=0; i<v; i++){
                par[i]=-1;
                rank[i]=1;
            }

            int ans=0;
            for(auto i:l){
                int a=i.first.first;
                int b=i.first.second;
                int w=i.second;

                if(findSet(a, par)!=findSet(b, par)){
                    unionSet(a, b, par, rank);
                    ans+=w;
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

    cout<<"MST = "<<g.kruskalsMST();
    return 0;
}