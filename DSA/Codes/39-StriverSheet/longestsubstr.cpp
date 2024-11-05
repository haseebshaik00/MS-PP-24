int lengthOfLongestSubstring(string s) {
        int i=0, n=s.length(), ans=0, count=0, start=0;
        unordered_map<char, int> m;
        for(int i=0; i<n; i++){
            char c = s[i];
            if(!m[c]){
                m[c]++;
                ans = max(ans, ++count);
            }
            else{
                while(m[c]){
                    m[s[start]]--;
                    start++; count--;
                }
                m[c]++;
                count++;
            }
        }
        return ans;
    }