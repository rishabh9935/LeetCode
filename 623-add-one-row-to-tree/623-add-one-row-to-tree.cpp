
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
    void help(TreeNode* temp, int val, int depth, int cd){
        if(temp == NULL) return;
        if(cd == depth-1){
            TreeNode* newnodeL = new TreeNode();
            newnodeL->val = val;
            TreeNode* newnodeR = new TreeNode();
            newnodeR->val = val;
            newnodeL->left = temp->left;
            temp->left = newnodeL;
            newnodeR->right = temp->right;
            temp->right = newnodeR;
        }
        help(temp->left, val, depth, cd+1);
        help(temp->right, val, depth, cd+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == NULL) return root;
        TreeNode* temp = root;
        if(depth == 1){
            TreeNode* newnode = new TreeNode();
            newnode -> val = val;
            newnode->left = root;
            return newnode;
        }
        help(temp, val, depth, 1);
        return root;
    }
};


