class Solution {
public:
    // 1D compressed	Linear prefix (finite states)	
    // O(n)	O(1)	hold=max(hold, rest-p), sold=hold+p, rest=max(rest,sold)	
    // 3-state DP (hold/sold/rest).	Bottom-up; i = 0→n-1 (forward)
    int maxProfit(vector<int>& prices) {
        int s0=0, s1=-prices[0], s2=-1;
        for(int i=1; i<prices.size(); ++i){
            int p = prices[i];
            int ns0 = max(s0, s2);
            int ns1 = max(s1, s0-p);
            int ns2 = s1+p;
            s0=ns0; s1=ns1; s2=ns2;
        }
        return max(s0, s2);
    }
};