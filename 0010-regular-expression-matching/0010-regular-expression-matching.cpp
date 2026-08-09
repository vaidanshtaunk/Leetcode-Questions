class Solution {
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp) {

        // Pattern khatam ho gaya
        if (j == p.length()) {
            return i == s.length();
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Current characters match kar rahe hain?
        bool match = (i < s.length() &&
                     (s[i] == p[j] || p[j] == '.'));

        // Agar next character '*'
        if (j + 1 < p.length() && p[j + 1] == '*') {

            // 1. '*' ko zero times use karo
            // 2. Current character match karke '*' ko continue karo
            dp[i][j] = solve(s, p, i, j + 2, dp) ||
                       (match && solve(s, p, i + 1, j, dp));

            return dp[i][j];
        }

        // Normal character ya '.'
        if (match) {
            dp[i][j] = solve(s, p, i + 1, j + 1, dp);
            return dp[i][j];
        }

        // Match nahi hua
        dp[i][j] = false;
        return false;
    }

    bool isMatch(string s, string p) {

        vector<vector<int>> dp(
            s.length() + 1,
            vector<int>(p.length() + 1, -1)
        );

        return solve(s, p, 0, 0, dp);
    }
};

