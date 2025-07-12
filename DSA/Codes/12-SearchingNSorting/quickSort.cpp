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


// random pivot
class Solution {
public:
    int partition(vector<int> &arr, int s, int e){
        int pivotIndex = s + rand() % (e - s + 1);
        swap(arr[pivotIndex], arr[e]);
        int p = arr[e], i=s-1;
        for(int j=s; j<e; ++j)
            if(arr[j] <= p) swap(arr[++i], arr[j]);
        swap(arr[++i], arr[e]);
        return i;
    }

    void quickSort(vector<int> &arr, int s, int e){
        if(s>=e) return;
        int p = partition(arr, s, e);
        quickSort(arr, s, p-1);
        quickSort(arr, p+1, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};