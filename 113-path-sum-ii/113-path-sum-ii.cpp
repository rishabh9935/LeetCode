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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> running;
        dfs(root, 0, ans, running, targetSum);
        
        return ans;
    }
    
    void dfs(TreeNode* root, int cur, vector<vector<int>> &ans, vector<int> running, int targetSum){
        if(root == NULL) 
            return;
        
        int tSum = cur + root->val;
        running.push_back(root->val);
        
        if(root->left==NULL && root->right == NULL && tSum == targetSum ){
            ans.push_back(running);
            return;
        }
        dfs(root->left, tSum, ans, running, targetSum);
        dfs(root->right, tSum, ans, running, targetSum);
        
    }
};