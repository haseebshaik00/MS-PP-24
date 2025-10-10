template<typename T>
class Node{
public:
    string key;
    T val;
    Node<T> *next;

    Node(string s, T value){
        key = s; val = value;
        next = nullptr;
    }

    ~Node(){
        if(next) delete next;
    }
};

class HashTable{
public:
    Node<T> **table;
    int currentSize, tableSize;

    HashTable(int tableSize=7){
        currentSize = 0;
        table = new Node<T> *[tableSize];
        for(int i=0; i<tableSize; ++i)
            table[i] = nullptr;
    }

    int hashFn(string s){
        int idx=0, p=1;
        for(int i=0; i<s.length(); ++i){
            idx += s[i]*p;
            idx = idx%tableSize;
            p = p * 27;
        }
        return idx;
    }

    bool isPrime(){

    }

    int nextPrime(){

    }

    void rehash(){
        Node<T> **oldTable = table;

    }

    insert(){

    }

    erase(){

    }

    search(){

    }

    [](){

    }

    void print(){
        
    }

    ~HashTable(){
        
    }
};