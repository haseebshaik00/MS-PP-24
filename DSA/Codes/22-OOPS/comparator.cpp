#include<bits/stdc++.h>
using namespace std;

class Book{
public:
    string name;
    int price;

    Book(string name, int price){
        this->name = name;
        this->price = price;
    }
};

class Bookcompare{
public:
    bool operator()(Book a, Book b){
        if(a.name == b.name)
            return true;
        return false;
    }
};

template <class Iterator, class T, class Compare>
Iterator searchIt(Iterator start, Iterator end, T key, Compare cmp){
    while(start!=end){
        if(cmp(*start, key))
            return start;
        start++;
    }
    return end;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    list<Book> l;
    Book c("abc", 99);
    Book d("ghi", 92);
    Book e("jkl", 93);
    l.push_back(c);
    l.push_back(d);
    l.push_back(e);
    Book f("abc", 200);

    Bookcompare cmp;
    auto it = searchIt(l.begin(), l.end(), f, cmp);
    if(it!=l.end()){
        cout<<"Found"<<endl;
        cout<<(*it).price<<endl;
    }
    else cout<<"Not Found"<<endl;
    return 0;
}
