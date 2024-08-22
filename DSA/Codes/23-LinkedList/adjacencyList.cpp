#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    list<pair<int,int>> *l = new list<pair<int,int>>[3];
    for(int i=0; i<3; i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        l[x].push_back(make_pair(y, wt));
        l[y].push_back(make_pair(x, wt));
    }
    for(int i=0; i<3; i++){
        cout<<"["<<i<<"]"<<"->";
        for(auto x:l[i])
            cout<<"("<<x.first<<","<<x.second<<")"<<" ; ";
        cout<<endl;
    }

	return 0;
}
