void bubbleSortRec(vector<int>& arr, int n){
        if(n == 1) return;
        int count = 0;
        for(int j=0; j<n-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                count++;
            }
        }
        if(!count) return;
        bubbleSortRec(arr, n-1);
    }
    
    void bubbleSort(vector<int>& arr) {
        bubbleSortRec(arr, arr.size());
    }