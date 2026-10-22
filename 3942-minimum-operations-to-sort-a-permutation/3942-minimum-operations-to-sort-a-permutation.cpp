class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        bool inc = true;
        bool dec = true;

        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n;

            if (nums[next] != (nums[i] + 1) % n) {
                inc = false;
            }

            if (nums[next] != (nums[i] - 1 + n) % n) {
                dec = false;
            }
        }

        int ans = INT_MAX;

        if (inc) {
            int left = (n - nums[0]) % n;

            ans = min(ans, left);

            if (left > 0) {
                ans = min(ans, n - left + 2);
            }
        }

        if (dec) {
            int x = (nums[0] + 1) % n;

            ans = min(ans, 1 + min(x, (n - x) % n));
        }

        if (ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};