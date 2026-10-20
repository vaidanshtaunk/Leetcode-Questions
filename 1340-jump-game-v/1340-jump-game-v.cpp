class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& arr, int d, int i) {
        if (dp[i] != -1) {
            return dp[i];
        }

        int n = arr.size();
        int ans = 1;

        // Jump to the right
        for (int j = i + 1; j < n && j <= i + d; j++) {
            if (arr[j] >= arr[i]) {
                break;
            }

            ans = max(ans, 1 + solve(arr, d, j));
        }

        // Jump to the left
        for (int j = i - 1; j >= 0 && j >= i - d; j--) {
            if (arr[j] >= arr[i]) {
                break;
            }

            ans = max(ans, 1 + solve(arr, d, j));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();

        dp.assign(n, -1);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(arr, d, i));
        }

        return ans;
    }
};