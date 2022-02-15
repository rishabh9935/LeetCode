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
    void dfs(TreeNode* root,vector<int>& in){
        if(root == NULL)
            return;
        dfs(root -> left, in);
        in.push_back(root -> val);
        dfs(root -> right, in);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        dfs(root, in);
        return in;
    }
};