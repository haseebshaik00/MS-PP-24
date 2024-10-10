#include<bits/stdc++.h>
using namespace std;

class Car{
private:
    // Data Members / Attributes / Properties
    float price;
    int modelNo;
    string name;
    char *type = new char[10];

public:
    const int msp=20;
    // Default Constructor - Hidden
    // Overloaded Default Constructor
    Car():msp(100){ // Initialization List
        cout<<"Constructor"<<endl;
        price = 0.0;
        modelNo = 0;
        name = "";
        type = NULL;
    }
    // Parameterized Constructor
    Car(float p, int m, string n, char *t, int minprice=99):price(p), msp(minprice){
        cout<<"Parameterized Constructor"<<endl;
        // price=p; price already initialized in list
        modelNo=m;
        name=n;
        type=t;
    }
    // Copy Constructor
    Car(const Car &x):msp(x.msp){
        cout<<"Copy Constructor"<<endl;
        price = x.price;
        modelNo = x.modelNo;
        name = x.name;
        // Deep Copy
        type = new char[strlen(x.type)+1];
        strcpy(type, x.type);
    }
    // Copy Assignment Operator
    void operator=(const Car &x){
        cout<<"Copy Assignment Operator"<<endl;
        price = x.price;
        modelNo = x.modelNo;
        name = x.name;
        // Deep Copy through Copy Assignment Operator
        type = new char[strlen(x.type)+1];
        strcpy(type, x.type);
    }
    // Getters
    float getPrice() const{
        return price;
    }
    int getModel() const{
        return modelNo;
    }
    string getName() const{
        return name;
    }
    char* getType() const{
        return type;
    }
    // Setters
    void setPrice(const float p){
        price = p;
    }
    void setModel(const int m){
        modelNo = m;
    }
    void setName(const string n){
        name = n;
    }
    void setType(char *t){
        type = t;
    }
    // Member Functions / Methods
    float discount(const float n){
        price = (1-n/100) * price;
        return (1-n/100) * price;
    }
    void print() const{
        cout<<"Name: "<<name<<endl<<"Model No.: "<<modelNo<<endl<<"Price: "<<price<<endl<<"Type: "<<type<<endl<<"MSP: "<<msp<<endl;
    }
    void changeType() const{
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
    (*g).print();
    g->print();
    delete g;
    // c.price = 100.0;
    // c.modelNo = 1;
    // c.name = "Audi";
    c.print();
    cout<<sizeof(Car)<<" "<<sizeof(c)<<endl;
    d.discount(30);
    d.print();
    e.changeType();
    f.changeType();
    e.print();
    f.print();

    return 0;
}
