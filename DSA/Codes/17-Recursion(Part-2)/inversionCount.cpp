class Solution {
  public:
    // Function to count inversions in the array.
    int count = 0, temp[100001];
    void invMerge(vector<int> &arr, int s, int e){
        int mid = s + (e - s) / 2;
        int i=s, j=mid+1, k = s;
        while(i<=mid && j<=e){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                count += (mid - i + 1);
                temp[k++] = arr[j++];
            }
        }
        while(i<=mid) temp[k++] = arr[i++];
        while(j<=e) temp[k++] = arr[j++];
        for(int i=s; i<=e; ++i)
            arr[i] = temp[i];
    }    
    
    void invCount(vector<int> &arr, int s, int e){
        if(s>=e) return;
        int mid = s + (e - s) / 2;
        invCount(arr, s, mid);
        invCount(arr, mid+1, e);
        invMerge(arr, s, e);
    }
    
    int inversionCount(vector<int> &arr) {
        count = 0;
        int n = arr.size();
        invCount(arr, 0, n-1);
        return count;
    }
};