#include<bits/stdc++.h>
using namespace std;

class Car{
private:
    // Data Members
    float price;
    int modelNo;
    string name;

public:
    // Default Constructor - Hidden
    // Overloaded Default Constructor
    Car(){
        cout<<"Constructor"<<endl;
        price = 0.0;
        modelNo = 0;
        name = "";
    }
    // Parameterized Constructor
    Car(float p, int m, string n){
        cout<<"Parameterized Constructor"<<endl;
        price=p;
        modelNo=m;
        name=n;
    }
    // Getters
    float getPrice(){
        return price;
    }
    int getModel(){
        return modelNo;
    }
    string getName(){
        return name;
    }
    // Setters
    void setPrice(float p){
        price = p;
    }
    void setModel(int m){
        model = m;
    }
    void setName(string n){
        name = n;
    }
    // Member Functions
    float discount(float n){
        price = (1-n/100) * price;
        return (1-n/100) * price;
    }
    void print(){
        cout<<"Name: "<<name<<endl<<"Model No.: "<<modelNo<<endl<<"Price: "<<price<<endl;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Car c;
    Car d(100.0, 1, "Audi");
    // c.price = 100.0;
    // c.modelNo = 1;
    // c.name = "Audi";
    cout<<sizeof(Car)<<" "<<sizeof(c)<<endl;
    d.discount(30);
    d.print();

    return 0;
}
