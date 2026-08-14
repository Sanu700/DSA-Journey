class Solution {
public:
    int k;
    int ans;

    void dfs(TreeNode* root) {
        if(!root)
            return;

        // Left first → smaller values first
        dfs(root->left);

        k--;

        if(k == 0) {
            ans = root->val;
            return;
        }

        dfs(root->right);
    }

    int kthSmallest(TreeNode* root, int K) {
        k = K;
        dfs(root);
        return ans;
    }
};