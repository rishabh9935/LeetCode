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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int tNodes;
        int cLeft = 0 , cRight = 0;
        cLeft = leftHeight(root);
        cRight = rightHeight(root);
        if(cLeft == cRight){
            tNodes = pow(2,cLeft) - 1;
            return tNodes;
        }
        tNodes = 1+countNodes(root->left)+countNodes(root->right);
        return tNodes;
    }
    int leftHeight(TreeNode* root){
        int cLeft = 0;
        while(root){
                cLeft++;
                root = root->left;
        }
        return cLeft;
    }
    int rightHeight(TreeNode* root){
        int cRight = 0;
        while(root){
                cRight++;
                root = root->right;
            }
        return cRight;
    }
    
    // int countNodes(TreeNode* root) {
    //     if(root == NULL) return 0;
    //     int tNodes;
    //     queue<TreeNode*> ql,qr;
    //     ql.push(root);
    //     qr.push(root);
    //     int cLeft = 0 , cRight = 0;
    //     while(!ql.empty()){
    //         TreeNode* curr = ql.front();
    //         ql.pop();
    //         if(curr->left){
    //             cLeft++;
    //             ql.push(curr->left);
    //         }
    //     }
    //     while(!qr.empty()){
    //         TreeNode* curr = qr.front();
    //         qr.pop();
    //         if(curr->right){
    //             cRight++;
    //             qr.push(curr->right);
    //         }
    //     }
    //     if(cLeft == cRight){
    //         tNodes = pow(2,cLeft)-1;
    //         return tNodes;
    //     }
    //     tNodes = 1+countNodes(root->left)+countNodes(root->right);
    //     return tNodes;
    // }

};