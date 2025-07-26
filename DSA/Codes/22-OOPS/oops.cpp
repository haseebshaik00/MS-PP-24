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
        ii) Deep copy: not only copies data member values but also makes copies of dynamically allocated memory that the members points to
        iii) Copy assignment operator: copy constructor can be called only once, where as copy assignment operator can be called mutiple times, can be overloaded 
                with operator loading of "equals"
5) Destructors
6) this keyword: special pointer in cpp that points to the current object = this->x is same as *(this).x
7) Initialization List and const:
    a) Initialization List: shorter format to declare values, const values can also be declared in this
    b) const variable: initialized once, value doesn't change but we can read tho
    c) const parameters: whose values aren't changed inside the function
    d) const functions: functions that don't change the data members values of the class
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
13) Friend class and Friend Function: In C++, private and protected members of a class cannot normally be accessed from outside the class. But sometimes, you might 
want a specific external function or another class to access those private/protected members without making everything public. To do that, you use the keyword friend.
Friend Function: A friend function is not a member of the class but has access to its private and protected data.
Friend Class: If one class needs to access private/protected members of another class, make it a friend class.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// ======= FRIEND FUNCTION DEMO FORWARD DECLARATION =======
class Teacher;

// ======= ABSTRACT CLASS =======
class IPerson {
public:
    virtual void introduce() const = 0;  // pure virtual function
    virtual ~IPerson() {}               // virtual destructor
};

// ======= BASE CLASS =======
class Person : public IPerson {
public:
    const int id;               // const member (must be initialized)
    int age;
    string name;
    static int population;      // static variable - shared accross all the objects

    // If no constuctor is defined, C++ implicitly implements a default constructor

    /*
    // Default constructor - overloaded - [Non-parameterized]
    Person() : id(0), age(0), name("Unknown") {
        cout << "Default constructor called\n";
        population++;
    }
    */
    //Default constructor with default values - overloaded - [parameterized]
    Person(int x = 0) : id(0), age(x), name("Default") {
        cout<<"Constructor with default argument called for "<<name<<endl;
        population++;
    }

    // Parameterized constructor - usually used!
    Person(int age, string name, int personID = 0) : id(personID), age(age), name(name) {
        cout<<"Parameterized constructor called for "<< name<<endl;
        population++;
    }

    // Copy constructor (Shallow copy)
    Person(const Person& p) : id(p.id), age(p.age), name(p.name) {
        cout << "Shallow copy constructor called\n";
    }

    // const function and parameter
    bool isVoteEligible(const bool hasSSN) const {
        return hasSSN && age >= 18;
    }

    // Virtual function for polymorphism
    virtual void introduce() const override {
        cout << "Hi, I'm " << name << ", age " << age << ", ID " << id << ".\n";
    }

    static int getPopulation() {
        return population;
    }

    virtual ~Person() {
        cout << "Destructor of Person called for " << name << endl;
        population--;
    }
};

// This is the definition and initialization of a static data member outside the class. It is shared among all instances of the Person class.
// There is only one copy of it, regardless of how many objects are created. It must be defined outside the class (as it's not tied to any one object).
int Person::population = 0;

// ======= STUDENT CLASS =======
class Student : virtual public Person {
public:
    int* marks;

    // Default constructor
    Student() : Person() {
        marks = new int[3]{0};
    }

    // Parameterized constructor
    Student(int age, string name, int id, int m1 = 0, int m2 = 0, int m3 = 0)
        : Person(age, name, id) {
        marks = new int[3]{m1, m2, m3};
        cout << "Student parameterized constructor called\n";
    }

    // Deep copy constructor
    Student(const Student& s) : Person(s) {
        marks = new int[3];
        for (int i = 0; i < 3; ++i)
            marks[i] = s.marks[i];
        cout << "Deep copy constructor called\n";
    }

    // Copy assignment operator
    void operator=(const Student& s) {
        for (int i = 0; i < 3; ++i)
            marks[i] = s.marks[i];
        cout << "Copy assignment operator called\n";
    }

    void introduce() const override {
        cout << "I'm Student " << name << ", age " << age << ", ID " << id << ".\n";
    }

    ~Student() {
        delete[] marks;
        marks = nullptr;
        cout << "Student destructor called\n";
    }
};

// ======= TEACHER CLASS =======
class Teacher : virtual public Person {
private:
    double salary;

public:
    Teacher() : Person(), salary(0.0) {}
    Teacher(string name, int age, int id, double salary) : Person(age, name, id), salary(salary) {}

    void setSalary(double salary) {
        this->salary = salary;
    }

    double getSalary() const {
        return salary;
    }

    void introduce() const override {
        cout << "I'm Teacher " << name << ", teaching with salary $" << salary << endl;
    }

    friend class TA;                    // Friend class
    friend void revealSalary(const Teacher& t);  // Friend function
};

// ======= FRIEND FUNCTION =======
void revealSalary(const Teacher& t) {
    cout << "[Friend Function] Teacher " << t.name << "'s salary is $" << t.salary << endl;
}

// ======= TA CLASS (MULTIPLE INHERITANCE) =======
class TA : public Student, public Teacher {
public:
    TA(string name, int age, int id, double salary)
        : Person(age, name, id), Student(age, name, id), Teacher(name, age, id, salary) {
        marks = new int[3]{90, 95, 100};
    }

    void introduce() const override {
        cout << "I'm TA " << name << ", ID " << id << ", also assist teacher with salary $" << getSalary() << endl;
    }

    void showTeacherSalary() {
        cout << "[Friend Class] Teacher salary accessed by TA: $" << Teacher::getSalary() << endl;
    }
};

// ======= STATIC OBJECT DEMO =======
void staticObjectDemo() {
    static Person staticPerson(99, "StaticUser", 999);
    staticPerson.introduce();
}

// ======= MAIN =======
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "--- Object Creation ---\n";
    Person p1;
    Person p2(25, "Alice", 101);
    Person p3 = p2;  // copy constructor

    cout << "\n--- Student Example ---\n";
    Student s1;
    s1.name = "Bob";
    s1.age = 20;
    s1.introduce();

    Student s2 = s1;  // deep copy constructor
    s2.marks[0] = 85;

    cout << "\n--- Teacher Example ---\n";
    Teacher t1("Dr. Smith", 45, 201, 70000);
    t1.introduce();
    revealSalary(t1);  // friend function

    cout << "\n--- TA Example ---\n";
    TA ta1("Charlie", 23, 301, 35000);
    ta1.introduce();
    ta1.showTeacherSalary();

    cout << "\n--- Static Object Demo ---\n";
    staticObjectDemo();
    staticObjectDemo();  // will not recreate object

    cout << "\n--- Vote Eligibility ---\n";
    cout << "Is " << p2.name << " eligible to vote? " << (p2.isVoteEligible(true) ? "Yes" : "No") << endl;

    cout << "\nTotal Person objects: " << Person::getPopulation() << endl;

    return 0;
}