class Solution {
public:
    // 2D (or center expand)	Interval DP	
    // O(n²)	O(1)	
    // Often solved via center expansion (O(1) space).	
    // Bottom-up;
    string longestPalindrome(string s) {
        int n = s.length(), L=0, R=0;
        for(int i=0; i<n; ++i){
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]) { 
                if(r-l > R-L) {L=l; R=r;}    
                --l; ++r;
            }
            l=i; r=i+1;
            while(l>=0 && r<n && s[l]==s[r]) { 
                if(r-l > R-L) {L=l; R=r;}
                --l; ++r;
            }
        }
        return s.substr(L, R-L+1);
    }
};