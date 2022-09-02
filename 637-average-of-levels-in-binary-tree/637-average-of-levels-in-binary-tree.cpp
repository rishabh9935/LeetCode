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
    void levelOrderTraversal(TreeNode* root, vector<double> &ans){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        double x = 0;
        int cnt = 0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                ans.push_back(x/cnt);
                x = 0;
                cnt = 0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                x += temp->val;
                cnt++;
                if(temp -> left){
                    q.push(temp->left);
                }
                if(temp -> right){
                    q.push(temp->right);
                }
            }
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        levelOrderTraversal(root, ans);
        return ans;
    }
};