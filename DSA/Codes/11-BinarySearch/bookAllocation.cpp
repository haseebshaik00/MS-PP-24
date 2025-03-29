bool allocateBooks(vector<int> &a, int n, int b, int mid) {
    int totalStd = 1, read = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > mid) return false; // can't allocate book bigger than mid
        if (read + a[i] <= mid)
            read += a[i];
        else {
            totalStd++;
            read = a[i];
            if (totalStd > b)
                return false;
        }
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    int n = A.size();
    if (B > n) return -1; // not enough books for students

    int low = *max_element(A.begin(), A.end());  // no student can get less than the largest book
    int  high = 0;
    for(int k=0; k<n; k++)
        high += A[k];
    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (allocateBooks(A, n, B, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
