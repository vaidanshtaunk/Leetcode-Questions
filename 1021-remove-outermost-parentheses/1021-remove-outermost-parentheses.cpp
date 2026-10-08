class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int level = 0;

        for (char c : s) {
            if (c == '(') {
                if (level > 0) {
                    ans += c;
                }
                level++;
            }
            else {
                level--;

                if (level > 0) {
                    ans += c;
                }
            }
        }

        return ans;
    }
};