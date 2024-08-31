class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for(int i=0; i<n; i++){
            char c = s[i];
            if(st.empty() || c=='(' || c=='{' || c=='[')
                st.push(c);
            else if((c==')' && st.top()=='(') || (c=='}' && st.top()=='{') ||
                    (c==']' && st.top()=='['))
                st.pop();
            else return false;
        }
        return st.empty();
    }
};