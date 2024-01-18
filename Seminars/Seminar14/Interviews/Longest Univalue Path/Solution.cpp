
class Solution {
public:
    int longestPath(TreeNode* root, int& res) {
        if (root == nullptr) {
            return 0;
        }
        int left = longestPath(root->left, res);
        int right = longestPath(root->right, res);

        int resL = 0;
        int resR = 0;

        if (root->left && root->left->val == root->val) {
            resL = left + 1;
        }
        if (root->right && root->right->val == root->val) {
            resR = right + 1;
        }
        res = max(res, resL + resR);
        return max(resL, resR);

    }

    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int res = 0;
        longestPath(root, res);
        return res;
    }
};