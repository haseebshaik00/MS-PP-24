int bookAllocate(vector<int> &a, int n, int b, int x){
    int totalStd=1, read=0;
    for(int i=0; i<n; i++){
        if(a[i] > x) return false;
        if(read+a[i] <= x)
            read += a[i];
        else{
            totalStd++;
            read = a[i];
            if(totalStd > b) return false;
        }
    }    
    return true;
}

int Solution::books(vector<int> &A, int B) {
    if (B > A.size()) return -1;
    int i=*max_element(A.begin(), A.end());
    int j=0, n=A.size();
    for(int k=0; k<n; k++)
        j += A[k];
    int ans=j;
    while(i<=j){
        int mid = (i+j)/2;
        if(bookAllocate(A, n, B, mid)){
            ans = mid;
            j = mid - 1;
        }
        else i=mid+1;
    }
    return ans;
}
