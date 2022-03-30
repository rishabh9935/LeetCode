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
    TreeNode* insertIntoBST(TreeNode* root, int val){
        if(root==NULL) {
            return new TreeNode(val);
        }
        TreeNode* last = root;
        TreeNode* prev;
        // TreeNode* node = new TreeNode(val);
        while(last){
            if(val < last->val){
                if(last->left!=NULL)
                    last = last->left;
                else{
                    last->left = new TreeNode(val);
                    break;}
            }
            else{
                if(last->right!=NULL)
                    last = last->right;
                else{
                    last->right = new TreeNode(val);
                    break;}
            }
        }
        // if(last->val < val) prev->right = new TreeNode(val);
        // else 
        //     prev->left = new TreeNode(val);
        return root;
    }
};