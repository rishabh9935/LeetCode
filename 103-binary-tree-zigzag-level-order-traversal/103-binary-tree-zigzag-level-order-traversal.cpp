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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> v(size);
            for(int i=0;i<size;i++){
                int index;
                TreeNode* node;
                node = q.front();
                q.pop();
                if(flag == true) index = i;
                else index = size - 1-i;
                v[index]=node->val;
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                }
            flag = !flag;
            ans.push_back(v);
        }
        return ans;
    }
};