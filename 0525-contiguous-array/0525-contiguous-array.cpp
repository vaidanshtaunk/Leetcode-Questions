class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        
        // Balance 0 initially at index -1
        mp[0] = -1;
        
        int sum = 0;
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            
            // Treat 0 as -1 and 1 as +1
            if (nums[i] == 0)
                sum--;
            else
                sum++;
            
            // Same sum seen before
            if (mp.find(sum) != mp.end()) {
                ans = max(ans, i - mp[sum]);
            }
            else {
                // Store first occurrence only
                mp[sum] = i;
            }
        }
        
        return ans;
    }
};