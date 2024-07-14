#include<bits/stdc++.h>
using namespace std;

class Car{

    public:
        string name;
        int x, y;

    Car(){}
    Car(string n, int x, int y){
        name = n;
        this->x = x;
        this->y = y;
    }

    int dist(){
        return x*x + y*y;
    }

};

bool comp(Car a, Car b){
    if(a.dist() == b.dist()){
        return a.name < b.name;
    }
    return a.dist() < b.dist();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;
    string s;
    cin>>n;
    vector<Car> v;
    cin.get();
    for(int i=0; i<n; i++){
        cin>>s>>x>>y;
        Car temp(s, x, y);
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), comp);
    for(int i=0; i<n; i++){
        cout<<v[i].name<<" "<<v[i].x<<" "<<v[i].y<<endl;
    }

    return 0;
}
