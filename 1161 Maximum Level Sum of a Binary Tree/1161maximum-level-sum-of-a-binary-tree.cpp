class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 1, ans = 1;
        long long mx = LLONG_MIN;

        while (!q.empty()) {
            int sz = q.size();
            long long sum = 0;
            for (int i = 0; i < sz; i++) {
                auto t = q.front(); q.pop();
                sum += t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            if (sum > mx) {
                mx = sum;
                ans = lvl;
            }
            lvl++;
        }
        return ans;
    }
};
