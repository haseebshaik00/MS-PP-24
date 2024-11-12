#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    map<int, list<int>> l;

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void shortestPath(int x){
        map<int, int> dist;
        queue<int> q;
        q.push(x);
        for(auto x:l)
            dist[x.first] = INT_MAX;
        dist[x]=0;
        while(!q.empty()){
            int y = q.front();
            q.pop();
            for(auto a:l[y]){
                if(dist[a] == INT_MAX){
                    q.push(a);
                    dist[a] = dist[y]+1;
                }
            }
        }
        for(auto x:dist)
            cout<<x.first<<" "<<dist[x.first]<<endl;
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
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.shortestPath(0);

    return 0;
}
