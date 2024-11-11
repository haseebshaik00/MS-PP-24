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

    void printGraph(){
        for(int i=0; i<v; i++){
            cout<<"Vertex["<<i<<"]"<<" -> ";
            for(auto x:l[i])
                cout<<x<<" ";
            cout<<endl;
        }
    }

    void bfs(int x){
        unordered_map<int, bool> visited;
        queue<int> q;
        q.push(x);
        visited[x]=true;
        while(!q.empty()){
            int y = q.front();
            q.pop();
            cout<<y<<" ";
            for(auto a:l[y]){
                if(!visited[a]){
                    q.push(a);
                    visited[a] = true;
                }
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.bfs(0);

    return 0;
}
