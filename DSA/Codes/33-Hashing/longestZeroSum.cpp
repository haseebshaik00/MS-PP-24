
int maxLen(vector<int>& a, int n) {
        for(int i=1; i<n; i++)
            a[i] += a[i-1];
        int cMax=0, tMax=0;
        unordered_map<int, int> m;
        m.insert({0, -1});
        for(int i=0; i<n; i++){
            if(m.find(a[i]) == m.end())
                m.insert({a[i], i});
            else{
                cMax = i-m[a[i]];
                tMax = max(cMax, tMax);
            }
        }
        return tMax;
    }