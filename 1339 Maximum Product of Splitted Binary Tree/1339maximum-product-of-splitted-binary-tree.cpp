class Solution {
public:
    long long maxProd = 0;
    long long totalSum = 0;
    const int MOD = 1e9 + 7;
    
    long long sum(TreeNode* root) {
        if (!root) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    
    long long dfs(TreeNode* root) {
        if (!root) return 0;
        long long left = dfs(root->left);
        long long right = dfs(root->right);
        long long subTreeSum = root->val + left + right;
        maxProd = max(maxProd, subTreeSum * (totalSum - subTreeSum));
        return subTreeSum;
    }
    
    int maxProduct(TreeNode* root) {
        totalSum = sum(root);
        dfs(root);
        return maxProd % MOD;
    }
};