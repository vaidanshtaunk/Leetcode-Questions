class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> prev(n);
        vector<int> next(n);

        stack<int> st;

        // Previous Smaller
        for(int i = 0; i < n; i++) {

            while(!st.empty() &&
                  heights[st.top()] >= heights[i]) {

                st.pop();
            }

            prev[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while(!st.empty()) {
            st.pop();
        }

        // Next Smaller
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() &&
                  heights[st.top()] >= heights[i]) {

                st.pop();
            }

            next[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        int maxi = 0;

        for(int i = 0; i < n; i++) {

            int width = next[i] - prev[i] - 1;

            int area = heights[i] * width;

            maxi = max(maxi, area);
        }

        return maxi;
    }
};