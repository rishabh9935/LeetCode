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
    void countgood(TreeNode* root, int &count, int max){
        if(root==NULL) return;
        if(root->val >= max){
            count++;
            max = root->val;
        }
        countgood(root->left, count, max);
        countgood(root->right, count, max);
        
    }
    
    
    int goodNodes(TreeNode* root) {
        int count = 0;
        if(!root) return count;
        countgood(root, count, root->val);
        
        return count;
    }
};