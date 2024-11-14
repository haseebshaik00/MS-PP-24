#include<bits/stdc++.h>
using namespace std;

// Undirected Graph - with list implementation
class Graph{
public:
    int v;
    list<int> *l;

    Graph(int v){
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printGraph(){
        for(int i=0; i<v; i++){
            cout<<"Vertex["<<i<<"]"<<" -> ";
            for(auto x:l[i])
                cout<<x<<" ";
            cout<<endl;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.printGraph();

    return 0;
}
