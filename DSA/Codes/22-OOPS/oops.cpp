#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/* Concepts:

1) Object: Real world entities
2) Class: collection of objects / blueprint of entities
3) Class contains: Constructors, Destructor, access specifiers/access modifiers, data members/attributes/fields/propeties, member functions/methods, getters, setters
4) Constructors:
    a) Default: A default constructor is one that either: Takes no parameters, or Has all parameters with default values. If you don't define any constructor, 
        C++ automatically provides a default constructor that does nothing (but still constructs the object). However, if you define any other constructor, the compiler 
        does not generate a default constructor automatically unless you explicitly define it.
    b) Non-parameterized
    c) Parameterized
    d) Copy Constructor
        i) Shallow copy: copies properties of one object to another
        ii) Deep copy: not only copies data member values but also makes copies of dynamically allocated memory that the members points to.
5) Destructors
6) this keyword: special pointer in cpp that points to the current object = this->x is same as *(this).x
7) Initializer List: 
8) Access modidfiers/specifiers
9) OOPS Concepts
    a) Encapsulation: wrapping up of data members and methods in a single unit called class
    b) Inheritance: data members and methods of a base class is passed on to the derived class
        Mode of Inheritance: base class can be inherited as private, protected and public (mode)
        Types of Inheritance: Single Level, Multi-level, Multiple, Hierarchial, and Hybrid
    c) Polymorphism: ability of objects to take different forms or behaving in a different way based on the context in which they are used
        i) Compile Time Polymorphism: Function signature (return statement and parameters) is different
            = Constructor Overloading
            = Function Overloading
            = Operator Overloading
        ii) Runtime Polymorphism
            = Function Overriding: Function signature (return statement and parameters) is same, the implementation is different. 
                                   The parent class is said to be overriden!
            = Virtual Functions: member function that is **expected** to be redefined/overriden in the derived class
                    -- Can have implementation
                    -- Maybe overridden
                    -- Instantiable base class
                    -- virtual void func();
            = Pure Virtual Functions: member function that must be redefined/overriden in the derived class
                    -- No implementation
                    -- Must be overridden
                    -- Non instantiable base class
                    -- virtual void func() = 0;
    d) Abstraction: Hiding unnecessary/sensitive details and showing only the required/important parts [implemented using access modifiers]
    Data Hiding: Only hide unnecessary/sensitive details
10) Abstract class: used to provide a base class from which other classes can be derived, cannot be instantiated and are meant to be inherited, are typically used to 
                    define interfaces of derived class.
                    A class becomes abstract if it contains at least one pure virtual function. Can have non-virtual methods too.
11) Static keyword
    a) Static Variables:
        i) Inside Function: Variables declared as static in a function are created & initialised once for the lifetime of the program.
        ii) Inside Class: Static variables in a class are created & initialised once. They are shared by all the objects of the class.
    b) Static Objects: A static object is an object declared with the static keyword, which means: It is created only once. 
                       It retains its value/state between function calls. It is destroyed only when the program ends (not when the function/block ends).
                       Stored in static/global memory area. Save state across function calls.
13) Friend class and Friend Function: 
*/

class Teacher{
private:
    double salary;

public:
    string id, name, dept;

    Teacher(){
        cout<<"This is"
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}