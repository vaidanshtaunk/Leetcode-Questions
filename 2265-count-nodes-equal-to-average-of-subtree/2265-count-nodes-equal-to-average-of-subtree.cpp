class Solution {
public:
    int ans = 0;

    pair<int, int> solve(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }

        // Get sum and count from left subtree
        pair<int, int> left = solve(root->left);

        // Get sum and count from right subtree
        pair<int, int> right = solve(root->right);

        // Current subtree sum
        int sum = left.first + right.first + root->val;

        // Current subtree node count
        int count = left.second + right.second + 1;

        // Average = sum / count
        if (root->val == sum / count) {
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};