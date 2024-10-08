vector<int> minPartition(int N)
    {
        vector<int> denomination = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 }, v;
        int totalCoins=0;
        while(N > 0){
            auto idx = upper_bound(denomination.begin(), denomination.end(), N)-1-denomination.begin();
            v.push_back(denomination[idx]);
            N -= denomination[idx];
            totalCoins++;
        }
        return v;
    }