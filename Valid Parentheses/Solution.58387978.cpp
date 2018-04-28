class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0;i<s.length();i++) {
            if (s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]); 
            else {
                if (st.empty()) return 0;
                if (st.top()=='[' && s[i]==']') st.pop(); else
                if (st.top()=='(' && s[i]==')') st.pop(); else
                if (st.top()=='{' && s[i]=='}') st.pop(); else
                return 0;
            }
        }
        return st.empty();
    }
};