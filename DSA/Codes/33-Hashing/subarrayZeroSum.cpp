bool subArrayExists(int arr[], int n)
    {
        int pre=0;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            pre += arr[i];
            if(pre == 0 || m.find(pre) != m.end())
                return true;
            m.insert({pre,1});
        }
        return false;
    }