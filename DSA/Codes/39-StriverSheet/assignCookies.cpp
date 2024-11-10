int findContentChildren(vector<int>& g, vector<int>& s) {
        long long int ans=0, n=g.size(), m=s.size(), i=0, j=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(i<n && j<m){
            if(g[i] <= s[j]){
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }