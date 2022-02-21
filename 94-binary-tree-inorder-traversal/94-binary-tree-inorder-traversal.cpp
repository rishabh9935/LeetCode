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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *node = root;
        vector<int> ans;
        while(true){
            if(node != NULL){
                s.push(node);
                node = node -> left;
            }
            else{
                if(s.empty() == true) break;
                node = s.top();
                s.pop();
                ans.push_back(node->val);
                node = node -> right;
            }
        }
        return ans;
    }
};

//  void dfs(TreeNode* root,vector<int>& in){
//         if(root == NULL)
//             return;
//         dfs(root -> left, in);
//         in.push_back(root -> val);
//         dfs(root -> right, in);
//     }
    
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> in;
//         dfs(root, in);
//         return in;
//     }