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

    bool dfsHelper(vector<bool> &visited, vector<bool> &stackPack, int i){
        visited[i] = true;
        stackPack[i] = true;
        for(auto x:l[i]){
            if(stackPack[x])
                return true;
            else if(!visited[x]){
                if(dfsHelper(visited, stackPack, x))
                    return true;
            }
        }
        stackPack[i]=false;
        return false;
    }

    bool detectCycle(){
        int n = l.size();
        vector<bool> visited(n, false);
        vector<bool> stackPack(n, false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                if(dfsHelper(visited, stackPack, i))
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
