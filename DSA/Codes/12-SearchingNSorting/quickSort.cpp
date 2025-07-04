int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high], i=low-1;
    for(int j=low; j<high; j++)
        if(arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[++i], arr[high]);
    return i;
}

void quickSort(vector<int>& arr, int low, int high) {
    if(low>=high) return;
    int p = partition(arr, low, high);
    quickSort(arr, low, p-1);
    quickSort(arr, p+1, high);
}