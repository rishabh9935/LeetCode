/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* inOrder(int value,TreeNode* root){
        if(root==NULL) return NULL;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            root = s.top();
            s.pop();
            if(root->val == value){
                return root;
            }
            if(root->right != NULL) s.push(root->right);
            if(root->left != NULL) s.push(root->left);
        }
        return root;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int value = target->val;
        cout<<value;
        TreeNode* add = inOrder(value,cloned);
        return add;
    }
};