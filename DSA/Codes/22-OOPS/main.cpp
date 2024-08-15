#include<bits/stdc++.h>
using namespace std;

class Car{
private:
    // Data Members
    float price;
    int modelNo;
    string name;
    char *type = new char[10];

public:
    // Default Constructor - Hidden
    // Overloaded Default Constructor
    Car(){
        cout<<"Constructor"<<endl;
        price = 0.0;
        modelNo = 0;
        name = "";
        type = NULL;
    }
    // Parameterized Constructor
    Car(float p, int m, string n, char *t){
        cout<<"Parameterized Constructor"<<endl;
        price=p;
        modelNo=m;
        name=n;
        type=t;
    }
    // Copy Constructor
    Car(Car &x){
        cout<<"Copy Constructor"<<endl;
        price = x.price;
        modelNo = x.modelNo;
        name = x.name;
        // Deep Copy
        type = new char[strlen(x.type)+1];
        strcpy(type, x.type);
    }
    // Copy Assignment Operator
    void operator=(Car &x){
        cout<<"Copy Assignment Operator"<<endl;
        price = x.price;
        modelNo = x.modelNo;
        name = x.name;
        // Deep Copy through Copy Assignment Operator
        type = new char[strlen(x.type)+1];
        strcpy(type, x.type);
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
    char* getType(){
        return type;
    }
    // Setters
    void setPrice(float p){
        price = p;
    }
    void setModel(int m){
        modelNo = m;
    }
    void setName(string n){
        name = n;
    }
    void setType(char *t){
        type = t;
    }
    // Member Functions
    float discount(float n){
        price = (1-n/100) * price;
        return (1-n/100) * price;
    }
    void print(){
        cout<<"Name: "<<name<<endl<<"Model No.: "<<modelNo<<endl<<"Price: "<<price<<endl<<"Type: "<<type<<endl;
    }
    void changeType(){
        type[6] = 'B';
    }

    // Destructor
    ~Car(){
        cout<<"Destructor"<<endl;
        if(type!=NULL){
            delete []type;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Car c;
    Car d(100.0, 1, "Audi", "Class A");
    Car e(d);
    Car f;
    f=d;
    Car *g = new Car(100.0, 1, "Audi", "Class A");
    (*e).print();
    e->print();
    delete g;
    // c.price = 100.0;
    // c.modelNo = 1;
    // c.name = "Audi";
    cout<<sizeof(Car)<<" "<<sizeof(c)<<endl;
    d.discount(30);
    d.print();
    e.changeType();
    f.changeType();
    e.print();
    f.print();

    return 0;
}
