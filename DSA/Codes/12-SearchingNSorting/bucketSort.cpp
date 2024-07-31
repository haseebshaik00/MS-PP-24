#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
    string name;
    int marks;
};

void bucketSort(Student stnd[], int n){
    vector<Student> v[100];
    for(int i=0; i<n; i++)
        v[stnd[i].marks].push_back(stnd[i]);
    for(int i=0; i<100; i++){
        for(auto it=v[i].begin(); it!=v[i].end(); it++)
            cout<<(*it).name<<" "<<(*it).marks<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n;
    cin.get();
    Student stnd[n];
    string na;
    for(int i=0; i<n; i++){
        cin>>na>>m;
        stnd[i].name = na;
        stnd[i].marks = m;
    }
    bucketSort(stnd, n);

    return 0;
}
