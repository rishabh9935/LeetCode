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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) {
            return new TreeNode(val);
        }
        TreeNode* last = root;
        // TreeNode* node = new TreeNode(val);
        while(last){
            if(last->val < val ){
                if(last->right != NULL)
                    last = last->right;
                else{
                    last = last;
                    break;
                }
                
            }
            else {
                if(last->left != NULL)
                    last = last->left;
                else{
                    last = last;
                    break;
                }
            }
        }
        if(last->val > val) last->left = new TreeNode(val);
        else 
            last->right = new TreeNode(val);
        return root;
    }
};