class Solution {
public:
    string minWindow(string s, string t) {
        int sLength = s.length(), tLength = t.length();
        int sFreq[256]={0}, tFreq[256]={0};
        int minLength=INT_MAX, start = 0, count=0, startIdx=-1;

        // if length of substring > string
        if(tLength > sLength)
            return "";
        
        // feeding the substring freq array
        for(int i=0; i<tLength; i++)
            tFreq[t[i]]++;
        
        for(int i=0; i<sLength; i++){
            char ch = s[i];
            sFreq[ch]++;

            // add count if the t pattern is available
            if(tFreq[ch]!=0 && sFreq[ch] <= tFreq[ch])
                count++;
            
            // check if the substr has been achieved
            if(count == tLength){
                char c = s[start];

                // shrink
                while(tFreq[c]==0 || sFreq[c]>tFreq[c]){
                    sFreq[c]--;
                    start++;
                    c = s[start];
                }

                int windowSize = i-start+1;

                // find the min window size
                if(windowSize < minLength){
                    minLength = min(windowSize, minLength);
                    startIdx=start;
                }
            }
        }
        if(startIdx == -1) return "";
        return s.substr(startIdx, minLength);
    }
};