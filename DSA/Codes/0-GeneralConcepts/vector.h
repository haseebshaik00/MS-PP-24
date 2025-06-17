class vectorMock{
    int *a;
    int cs, ms;

    public:
    vectorMock(){
        cs=0; ms = 8;
        a = new int[ms];
    }

    void push_back(int x){
        if(cs == ms){
            int *newArray = new int[ms*2];
            for(int i=0; i<ms; i++)
                newArray[i] = a[i];
            delete []a;
            a=newArray;
            delete []newArray;
            newArray = NULL;
        }
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