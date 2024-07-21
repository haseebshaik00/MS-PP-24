#include<bits/stdc++.h>
#include "vector.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Vector a;
    a.push_back(2);
    a.push_back(3);
    a.push_back(8);
    a.push_back(8);
    a.push_back(1);
    a.pop_back();
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<a.size()<<endl;
    cout<<a.empty()<<endl;
    cout<<a.capacity()<<endl;
    cout<<a.at(2)<<endl;
    cout<<a[0];

    return 0;
}
