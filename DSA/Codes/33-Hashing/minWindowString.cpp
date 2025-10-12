string minWindow(string s, string t) {
        int n=s.length(), m=t.length(), A[128]={0}, B[128]={0};
        if(m>n) return "";
        for(auto &c: t) B[c]++;
        int start=0, minLen=INT_MAX, left=0, count=0;
        for(int right=0; right<n; right++){
            char c = s[right];
            A[c]++;
            // A[c]<=B[c] -- increase count only when the window has all the 
            // chars are available or about to reach all chars!
            if(B[c]>0 && A[c]<=B[c]) count++;
            while(count == m){
                char d = s[left];
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    start = left;
                }
                // A[d]<=B[d] -- remove redundant chars from left of the window but 
                // dont decrease the count as they are extra!
                // decrease the count only when the char is present in B!
                if(B[d]>0 && A[d]<=B[d]) count--;
                A[d]--;
                left++;
            }
        }
        return (minLen==INT_MAX) ? "" : s.substr(start, minLen);
    }