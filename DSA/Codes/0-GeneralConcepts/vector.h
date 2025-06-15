class vectorMock{
    int *a;
    int cs, ms;

    public:
    vectorMock(){
        cs=0; ms = 8;
        a = new int[ms];
    }

    void push_back(int x){
        if(cs == ms)
            ms = ms*2;
        a[cs] = x;
        cs++;
    }

    void pop_back(){
        cs--;
    }

    bool isEmpty(){
        return cs == 0;
    }

    int size(){
        return cs;
    }
};