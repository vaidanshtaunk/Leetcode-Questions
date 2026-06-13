class Solution {
public:
    int calculate(string s) {

        stack<int> st;

        int num = 0;
        char sign = '+';

        for(int i = 0; i < s.length(); i++) {

            char ch = s[i];

            if(isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            if((!isdigit(ch) && ch != ' ') || i == s.length() - 1) {

                if(sign == '+') {
                    st.push(num);
                }

                else if(sign == '-') {
                    st.push(-num);
                }

                else if(sign == '*') {

                    int top = st.top();
                    st.pop();

                    st.push(top * num);
                }

                else if(sign == '/') {

                    int top = st.top();
                    st.pop();

                    st.push(top / num);
                }

                sign = ch;
                num = 0;
            }
        }

        int ans = 0;

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};