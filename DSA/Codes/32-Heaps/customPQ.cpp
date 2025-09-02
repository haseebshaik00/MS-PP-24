#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Person{
public:
    string name;
    int age;
    
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }

    void print(){
        cout<<name<<" "<<age<<endl;
    }
};

class PersonCompare{
public:
    bool operator()(Person A, Person B){
        return A.age < B.age;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<Person, vector<Person>, PersonCompare> pq;

    Person A("Haseeb", 34);
    Person B("Harry", 47);
    Person C("KSI", 36);

    pq.push(A);
    pq.push(B);
    pq.push(C);

    while(!pq.empty()){
        Person X = pq.top();
        X.print();
        pq.pop();
    }

    return 0;
}