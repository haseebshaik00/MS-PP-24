template <typename T>
class Node{
public:
    string key;
    T val;
    Node<T>* next;

    Node(string key, T val){
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node(){
        if(next!=NULL)
            delete next;
    }
};

template <typename T>
class Hashmap{

    int hashFn(string s){
        int hashValue = 0, n=s.length(), p=1;
        for(int i=0; i<n; i++){
            hashValue += (s[i]*p)%tableSize;
            hashValue %= tableSize;
            p = (p*27)%tableSize;
        }
        return hashValue;
    }

    void rehash(){
        Node<T>** oldTable = table;
        int oldTableSize = tableSize;
        tableSize *= 2;
        currentSize = 0;
        table = new Node<T>*[tableSize];
        for(int i=0; i<tableSize; i++)
            table[i] = NULL;
        for(int i=0; i<oldTableSize; i++){
            Node<T>* temp = oldTable[i];
            while(temp != NULL){
                insert(temp->key, temp->val);
                temp=temp->next;
            }
            if(oldTable[i] != NULL)
                delete oldTable[i];
        }
        delete []oldTable;
    }

public:
    int currentSize;
    int tableSize;
    Node<T> **table;

    Hashmap(int ts=7){
        currentSize = 0;
        tableSize = ts;
        table = new Node<T>* [ts];
        for(int i=0; i<ts; i++)
            table[i] = NULL;
    }

    void insert(string s, T k){
        int h = hashFn(s);
        Node<T>* temp = new Node<T>(s, k);
        temp->next = table[h];
        table[h] = temp;
        currentSize++;

        // rehashing and loadfactor
        float loadFactor = currentSize/(1.0 * tableSize);
        float threshold = 0.75;
        if(loadFactor >= threshold)
            rehash();
    }

    void erase(string s){
        for(int i=0; i<tableSize; i++){
            Node<T>* temp = table[i], *prev = NULL;
            while(temp != NULL){
                if(temp->key == s){
                    if(prev != NULL)
                        prev->next = temp->next;
                    else
                        table[i] = temp->next;
                    temp->next = NULL;
                    delete temp;
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
        }
    }

    T* search(string s){
        for(int i=0; i<tableSize; i++){
            Node<T>* temp = table[i];
            while(temp != NULL){
                if(temp->key == s)
                    return &(temp->val);
                temp = temp->next;
            }
        }
        return NULL;
    }

    void print(){
        for(int i=0; i<tableSize; i++){
            Node<T>* temp = table[i];
            cout<<"Bucket= "<<i<<"->";
            while(temp != NULL){
                cout<<"("<<temp->key<<":"<<temp->val<<")"<<"->";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    T& operator[](string s){
        int *f = search(s);
        if(f == NULL){
            insert(s, 100);
            f = search(s);
        }
        return *f;
    }

};
