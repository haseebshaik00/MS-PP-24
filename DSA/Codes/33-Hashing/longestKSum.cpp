int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        unordered_map<int, int> m;
        m.insert({0, -1});
        int pre=0, cMax=0, tMax=0;
        for(int i=0; i<n; i++){
            pre += a[i];
            if(m.find(pre) == m.end())
                m.insert({pre, i});
            if(m.find(pre - k) != m.end()){
                cMax = i - m[pre-k];
                tMax = max(tMax, cMax);
            }
        }
        return tMax;
    } 