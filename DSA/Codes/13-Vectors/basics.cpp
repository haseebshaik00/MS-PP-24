#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // initialization and declaration
    vector<int> v;
    vector<int> v1{1,2,3,4,5};
    vector<int> v2(5,0);
    vector<int> v3(v1);
    vector<int> v4(v1.begin(), v1.end());

    // iterate
    for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        cout<<*it<<" ";
    cout<<endl;
    for(auto it=v1.begin(); it!=v1.end(); it++)
        cout<<*it<<" ";
    cout<<endl;
    for(int x:v1)
        cout<<x<<" ";
    cout<<endl;
    for(auto x:v1)
        cout<<x<<" ";
    cout<<endl;

    //input
    for(int i=0; i<5; i++){
        int d;
        cin>>d;
        v.push_back(d);
    }

    //methods
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl; // 8 but v1 has capacity as 5
    cout<<v.max_size()<<endl;
    v.push_back(6);
    v.push_back(7);
    v.pop_back();
    v.insert(v.begin()+2, 4);
    v.insert(v.begin()+3, 3, 5);
    v.erase(v.begin()+2);
    v.erase(v.begin()+2, v.begin()+4);
    v.resize(10); // capacity doesn't shrink -- size becomes small but capacity remains the same
    v.resize(100); // if size is larger than the current size then both size and capacity increases
    v.clear(); // empties the vector but doesn't release the space occupied by it
    // which means size becomes 0 but capacity remains intact
    cout<<v.empty()<<endl;
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
    vector<int> v6;
    v6.resize(100); // always do this

    return 0;
}
