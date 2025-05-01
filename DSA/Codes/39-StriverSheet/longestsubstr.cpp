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

// Sliding window approach
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> m;
    int n = s.length();
    int i = 0, j = 0, ans = 0;
    while (j < n) {
        if (m[s[j]] == 0) {
            m[s[j]]++;
            ans = max(ans, j - i + 1);
            j++;
        } else {
            m[s[i]]--;
            i++;
        }
    }
    return ans;
}