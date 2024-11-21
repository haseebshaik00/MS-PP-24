#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    public:
    unordered_map<T, list<pair<T, int>>> m;

    void addEdge(T src, T dest, int x, bool dir = true){
        m[src].push_back(make_pair(dest, x));
        if(dir)
            m[dest].push_back(make_pair(src, x));
    }

    void djikstra(T src){
        unordered_map<T, int> dist;
        for(auto x:m)
            dist[x.first] = INT_MAX;
        dist[src] = 0;
        set<pair<int, T>> s;
        s.insert(make_pair(0, src));
        while(!s.empty()){
            auto p = *(s.begin());
            T node = p.second;
            int distNode = p.first;
            s.erase(s.begin());
            for(auto x:m[node]){
                if(distNode+x.second < dist[x.first]){
                    T dest = x.first;
                    auto y = s.find(make_pair(dist[dest], dest));
                    if(y!=s.end())
                        s.erase(y);
                    dist[dest] = distNode+x.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }
        for(auto x:dist)
            cout<<x.first<<":"<<x.second<<endl;
    }

    void print(){
        for(auto x:m){
            cout<<x.first<<"->";
            for(auto y:x.second){
                cout<<y.first<<":"<<y.second<<"; ";
            }
            cout<<endl;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph<string> g;
    g.addEdge("Amritsar", "Delhi", 1);
    g.addEdge("Amritsar", "Jaipur", 4);
    g.addEdge("Jaipur", "Delhi", 2);
    g.addEdge("Jaipur", "Mumbai", 8);
    g.addEdge("Bhopal", "Agra", 2);
    g.addEdge("Mumbai", "Bhopal", 3);
    g.addEdge("Agra", "Delhi", 1);
    g.print();
    cout<<endl;
    g.djikstra("Amritsar");

    return 0;
}
