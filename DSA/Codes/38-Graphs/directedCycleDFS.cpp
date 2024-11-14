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


};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(, 2);
    g.addEdge(2, 3);
    //g.addEdge(1, 2);
    g.addEdge(3, 4);

    if(g.detectCycle()) cout<<"Cycle exists!";
    else cout<<"Cycle doesn't exists!";

    return 0;
}
