template <typename T>
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

template <typename T>
class HashTable{

    int hashFn(string s){
        int idx=0, p=1;
        for(int i=0; i<s.length(); ++i){
            idx += (s[i]*p)%tableSize;;
            idx = idx%tableSize;
            p = (p*27)%tableSize;;
        }
        return idx;
    }

    bool isPrime(int n){
        if(n <= 1) return false;
        if(n==2 || n==3) return true;
        if(n%2 == 0 || n%3 == 0) return false;
        for(int i=5; i*i<=n; i+=6){
            if(n%i == 0 || n%(i+2)==0) return false;
        }
        return true;
    }

    int nextPrime(int n){
        int temp = n, flag=false;
        while(!flag)
            if(isPrime(++temp)) flag=true;
        return temp;
    }

    void rehash(){
        Node<T> **oldTable = table;
        int oldTableSize = tableSize;
        tableSize *= 2; currentSize = 0;
        tableSize = nextPrime(tableSize);
        table = new Node<T> *[tableSize];
        for(int i=0; i<tableSize; i++)
            table[i] = nullptr;
        for(int i=0; i<oldTableSize; ++i){
            Node<T> *temp = oldTable[i];
            while(temp){
                insert(temp->key, temp->val);
                temp = temp->next;
            }
            if(oldTable[i]) delete oldTable[i];
        }
        delete []oldTable;
    }
    
public:
    Node<T> **table;
    int currentSize, tableSize;

    HashTable(int tableSize=7){
        this->tableSize = tableSize;
        currentSize = 0;
        table = new Node<T> *[tableSize];
        for(int i=0; i<tableSize; ++i)
            table[i] = nullptr;
    }

    void insert(string key, T value){
        int idx = hashFn(key);
        Node<T> *temp = new Node<T>(key, value);
        temp->next = table[idx];
        table[idx] = temp;
        ++currentSize;
        // loadfactor & rehash
        float loadfactor = (currentSize * 1.0)/tableSize;
        float thresholdValue = 0.75;
        if(loadfactor >= thresholdValue) rehash();
    }

    T* search(string key){
        int idx = hashFn(key);
        Node<T> *temp = table[idx];
        while(temp){
            if(temp->key == key) return &(temp->val);
            temp = temp->next;
        }
        return nullptr;
    }

    void erase(string key){
        if(!search(key)) return;
        int idx = hashFn(key);
        Node<T> *temp = table[idx], *prev=nullptr;
        while(temp){
            if(temp->key == key){
                if(!prev)   table[idx] = temp->next;
                else    prev->next = temp->next;
                temp->next = nullptr;
                --currentSize;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    T& operator[](string key){
        if(!search(key)) insert(key, T{});
        return *(search(key));
    }

    void print(){
        for(int i=0; i<tableSize; ++i){
            Node<T> *temp = table[i];
            cout<<"Bucket= "<<i<<"->";
            while(temp){
                cout<<"("<<temp->key<<":"<<temp->val<<")"<<"->";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    ~HashTable(){
        for(int i=0; i<tableSize; ++i)
           if(table[i]) delete table[i];
        delete []table;
    }
};