#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    map<int, list<int>> l;

    void addEdge(int x, int y, bool dir=true){
        l[x].push_back(y);
        if(!dir)
            l[y].push_back(x);
    }

    bool detectCycleHelper(int node, vector<bool> &visited, vector<bool> &stack){
        visited[node] = true;
        stack[node] = true;

        for(auto x: l[node]){
            if(stack[x])
                return true;
            else if(!visited[x]){
                bool hasCycle = detectCycleHelper(x, visited, stack);
                if(hasCycle) return true;
            }
        }
        stack[node] = false;
        return false;
    }

    bool detectCycle(){
        int n = l.size();
        vector<bool> visited(n, false);
        vector<bool> stack(n, false);
        return detectCycleHelper(0, visited, stack);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 5);
    g.addEdge(5, 6);
    // g.addEdge(4, 2);

    if(g.detectCycle()) cout<<"Cycle exists!";
    else cout<<"Cycle doesn't exists!";

    return 0;
}
