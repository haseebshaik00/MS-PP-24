class Vector{

    int *a, cs, ms;

    public:
    Vector(){
        a = new int[ms];
        cs=0; ms=1;
    }

    void push_back(int d){
        if(cs == ms){
            int* oldArr = a;
            a = new int[2 * ms];
            for(int i=0; i<ms; i++){
                a[i] = oldArr[i];
            }
            delete []oldArr;
            oldArr=0;
            ms = 2*ms;
        }
        a[cs] = d;
        cs++;
    }

    void pop_back(){
        cs--;
    }

    int front(){
        return a[0];
    }

    int back(){
        return a[cs-1];
    }

    bool empty(){
        return cs==0;
    }

    int size(){
        return cs;
    }

    int capacity(){
        return ms;
    }

    int at(int i){
        return a[cs];
    }

    int operator[](int x){
        return a[x];
    }
};
