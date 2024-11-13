#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    map<int, list<int>> l;

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(int x, map<int, bool> &visited){
        cout<<x<<" ";
        visited[x] = true;
        for(auto y:l[x])
            if(!visited[y])
                dfs_helper(y, visited);
    }

    void connectedGraphs(){
        map<int, bool> visited;
        int c=0;
        for(auto x:l){
            if(!visited[x]){
                cout<<c<<"-> ";
                dfs_helper(src, visited);
            }
            c++;
            cout<<endl;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(6, 5);
    g.addEdge(6, 7);
    g.addEdge(8, 8);
    g.connectedGraphs();

    return 0;
}