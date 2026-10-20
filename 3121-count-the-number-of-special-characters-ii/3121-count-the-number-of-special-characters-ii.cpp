class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);

        for (int i = 0; i < word.size(); i++) {
            char c = word[i];

            if (c >= 'a' && c <= 'z') {
                lastLower[c - 'a'] = i;
            }
            else {
                int index = c - 'A';

                if (firstUpper[index] == -1) {
                    firstUpper[index] = i;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 &&
                firstUpper[i] != -1 &&
                lastLower[i] < firstUpper[i]) {

                ans++;
            }
        }

        return ans;
    }
};