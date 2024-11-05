int romanToInt(string s) {
        unordered_map<char, int> m;
        int n=s.length(), ans=0;
        m.insert({'I', 1}); m.insert({'V', 5}); m.insert({'X', 10}); m.insert({'L', 50});
        m.insert({'C', 100}); m.insert({'D', 500}); m.insert({'M', 1000}); 
        for(int i=0; i<n; i++){
            if(m[s[i]] < m[s[i+1]])
                ans -= m[s[i]];
            else ans += m[s[i]];
        }
        return ans;
    }