class Solution {
public:
    string removeKdigits(string num, int k) {

        string st;

        for (char c : num) {

            // Remove bigger digits from the left
            // to make the number smaller
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }

            st.push_back(c);
        }

        // If k is still left, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (i < st.size() && st[i] == '0') {
            i++;
        }

        // Everything was removed / only zeros remain
        if (i == st.size()) {
            return "0";
        }

        return st.substr(i);
    }
};