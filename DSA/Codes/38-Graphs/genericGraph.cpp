#include<bits/stdc++.h>
using namespace std;

// Directed Graph with Map Implementation
class Graph{
public:
    unordered_map<string, list<pair<string, int>>> l;

    void addEdge(string a, string b, bool dir, int wt){
        if(dir)
            l[b].push_back(make_pair(a, wt));
        l[a].push_back(make_pair(b, wt));
    }

    void printGraph(){
        for(auto x:l){
            cout<<x.first<<" ";
            list<pair<string, int>> p = x.second;
            for(auto y:p)
                cout<<y.first<<" "<<y.second<<" - ";
            cout<<endl;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("A", "D", false, 50);
    g.addEdge("A", "C", true, 10);
    g.addEdge("B", "D", true, 30);
    g.addEdge("C", "D", true, 40);
    g.printGraph();

    return 0;
}
