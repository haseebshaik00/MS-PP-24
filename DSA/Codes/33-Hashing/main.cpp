#include<bits/stdc++.h>
using namespace std;
#include "hash.h"

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Hashmap<int> h;
    h.insert("Burger", 100);
    h.insert("Idli", 60);
    h.insert("Dosa", 70);
    h.insert("Pizza", 80);
    h.insert("Coke", 40);
    h.insert("Pepsi", 35);
    h.insert("Noodles", 75);
    h.insert("Maggi", 20);
    h.insert("Samosa", 55);
    h.print();
    cout<<endl;
    int* hSearch = h.search("Maggi");
    if(hSearch) cout<<"Found = "<<*hSearch<<endl;
    else cout<<"Not Found!"<<endl;
    h["Samosa"] = 50;
    cout<<"Samosa = "<<h["Samosa"]<<endl;
    h["Maggi"] += 20;
    cout<<"Maggi = "<<h["Maggi"]<<endl;
    cout<<endl;
    h.erase("Noodles");
    h.print();

    return 0;
}
