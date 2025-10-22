class Solution {
public:
    /// 2D (or center expand)	Interval DP	
    // O(n²)	O(1)	
    // Often solved via center expansion (O(1) space).	
    // Bottom-up;
    int countSubstrings(string s) {
        int n = s.length(), cnt=0;
        for(int i=0; i<n; ++i){
            int l=i, r=i;
            while(l>=0 && r<n && s[l] == s[r]) {--l; r++; cnt++;}
            l=i; r=i+1;
            while(l>=0 && r<n && s[l] == s[r]) {--l; r++; cnt++;}
        }
        return cnt;
    }
};