#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    map<int, list<int>> l;

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool detectCycleHelper(int y, map<int, bool> &visited, int parent){
        visited[y] = true;
        for(auto x:l[y]){
            if(!visited[x]){
                bool cyclePresent = detectCycleHelper(x, visited, y);
                if(cyclePresent) return true;
            }
            else if(x != parent){
                return true;
            }
        }
        return false;
    }

    bool detectCycle(){
        map<int, bool> visited;
        for(auto x: l){
            int node = x.first;
            if(!visited[node]){
                if(detectCycleHelper(node, visited, -1))
                    return true;
            }
        }
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(2, 3);
    //g.addEdge(1, 2);
    g.addEdge(3, 4);

    if(g.detectCycle()) cout<<"Cycle exists!";
    else cout<<"Cycle doesn't exists!";

    return 0;
}
