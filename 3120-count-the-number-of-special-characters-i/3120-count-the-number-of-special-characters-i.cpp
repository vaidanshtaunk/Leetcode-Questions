class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);

        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                lower[c - 'a'] = 1;
            }
            else {
                upper[c - 'A'] = 1;
            }
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (lower[i] == 1 && upper[i] == 1) {
                ans++;
            }
        }
      return ans;

    }  
};