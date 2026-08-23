class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.length();

        // dp[i] = true means s ke first i characters
        // dictionary words se ban sakte hain
        vector<bool> dp(n + 1, false);

        // Empty string ko valid maanenge
        dp[0] = true;

        for (int i = 1; i <= n; i++) {

            for (string word : wordDict) {

                int len = word.length();

                // Check karo word s ke end me fit ho raha hai ya nahi
                if (len <= i && dp[i - len]) {

                    if (s.substr(i - len, len) == word) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[n];
    }
};