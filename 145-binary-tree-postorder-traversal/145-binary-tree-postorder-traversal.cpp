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

    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        if(root == NULL) return ans;
        TreeNode *temp;
        TreeNode *curr = root;
        while(curr != NULL || !s.empty()){
            if(curr!=NULL){
                s.push(curr);
                curr = curr->left;
            }
            else{
                temp = s.top()->right;
                if(temp == NULL){
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while(!s.empty() && temp == s.top()->right){
                        temp = s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                    curr = temp;
            }
        }
        return ans;
    }
};


        //stack<TreeNode*> st1;
        // stack<TreeNode*> st2;
        // vector<int> ans;
        // if(root == NULL) return ans;
        // st1.push(root);
        // while(!st1.empty()){
        //     root = st1.top();
        //     st1.pop();
        //     st2.push(root);
        //     if(root->left != NULL) st1.push(root->left);
        //     if(root->right != NULL ) st1.push(root->right);
        // }
        // while(!st2.empty()){
        //     ans.push_back(st2.top()->val);
        //     st2.pop();
        // }
        // return ans;



    // void dfs(TreeNode* root,vector<int>& post){
    //     if(root == NULL)
    //         return;
    //     dfs(root -> left, post);
    //     dfs(root -> right, post);
    //     post.push_back(root -> val);
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> post;
    //     dfs(root, post);
    //     return post;
    // }