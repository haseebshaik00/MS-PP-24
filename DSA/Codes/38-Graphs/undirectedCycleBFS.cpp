#include<bits/stdc++.h>
using namespace std;

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

    bool isTree(){
        map<int, bool> isVisited;
        map<int, int> parent;
        for(int i=0; i<v; i++)
            parent[i] = i;
        int src = 0;
        queue<int> q;
        q.push(src);
        isVisited[src] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto x:l[node]){
                if(isVisited[x] && parent[node] != x)
                    return false;
                else if(!isVisited[x]){
                    isVisited[x] = true;
                    parent[x] = node;
                    q.push(x);
                }
            }
        }
        return true;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    // g.addEdge(0, 3);

    if(g.isTree()) cout<<"Tree"<<endl;
    else cout<<"Not Tree"<<endl;

    return 0;
}
