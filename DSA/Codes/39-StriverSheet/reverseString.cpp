class Solution {
public:
    string reverseWords(string s) {
        int i=0, n=s.length();
        string ans="";
        while(i<n && s[i] == ' ') i++;
        for(; i<n; i++){
            string tempAns="";
            int j=i;
            for(; s[j] != ' ' && j<n; j++)
                tempAns += s[j];
            while(s[j]==' ' && j<n) j++;
            i=j-1;
            if (ans == "") 
                ans = tempAns + ans;
            else 
                ans = tempAns + ' ' + ans;
        }
        return ans;
    }
};