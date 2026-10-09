class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            }
            else {
                // If the next character is not ')',
                // insert one ')' to complete the pair.
                if (i + 1 < n && s[i + 1] == ')') {
                    i++;
                }
                else {
                    ans++;
                }

                // Match this '))' pair with an '('.
                if (open > 0) {
                    open--;
                }
                else {
                    // Insert an '(' because no opening exists.
                    ans++;
                }
            }
        }

        // Each remaining '(' needs two ')'.
        ans += open * 2;

        return ans;
    }
};