int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), c=0, x=0;
    unordered_map<int, int> m;
    m.insert({0, 1});
    for(int i=0; i<n; i++){
        x ^= A[i];
        if(m[x^B] > 0) c+=m[x^B];
        m[x]++;
    }
    return c;
}
