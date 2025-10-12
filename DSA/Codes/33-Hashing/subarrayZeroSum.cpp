// piegon hole principle - O(n)
bool subArrayExists(int arr[], int n)
    {
        int pre=0;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            pre += arr[i];
            if(!pre || m.count(protected)) return true;
            m[pre]++;
        }
        return false;
}