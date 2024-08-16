#include<bits/stdc++.h>
using namespace std;

template <class It, class T>
It searchIt(It s, It e, T k){
    while(s!=e){
        if(*s == k)
            return s;
        s++;
    }
    return e;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    list<int> l;
    l.push_back(21);
    l.push_back(30);
    l.push_back(12);
    l.push_back(100);
    l.push_back(99);
    auto it = searchIt(l.begin(), l.end(), 120);
    if(it != l.end()) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;

    return 0;
}
