/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void help(TreeNode* root, int targetSum, int sum, bool &ans){
        if(root->left == NULL && root->right == NULL) {
            if(sum + root->val == targetSum){
                ans = true;
            }
            return;
        }
        sum += root->val;
        if(root->left != NULL)
            help(root->left, targetSum, sum, ans);
        if(root->right != NULL)
            help(root->right, targetSum, sum, ans);
    }
    
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        int sum = 0;
        bool ans = false;
        help(root, targetSum, sum, ans);
        return ans;
    }
};