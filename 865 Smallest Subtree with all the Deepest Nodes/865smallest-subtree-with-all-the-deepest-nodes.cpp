class Solution {
    public:
        TreeNode* subtreeWithAllDeepest(TreeNode* root) {
                return dfs(root).second;
                    }

                        pair<int, TreeNode*> dfs(TreeNode* node) {
                                if (!node) return {0, nullptr};
                                        auto L = dfs(node->left);
                                                auto R = dfs(node->right);
                                                        if (L.first > R.first) return {L.first + 1, L.second};
                                                                if (R.first > L.first) return {R.first + 1, R.second};
                                                                        return {L.first + 1, node};
                                                                            }
                                                                            };


