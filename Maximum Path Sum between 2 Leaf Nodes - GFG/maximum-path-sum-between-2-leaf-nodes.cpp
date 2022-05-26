// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    int solve(Node* root,int &maxi){
        if(root==NULL) return 0;
        if(root->left == NULL && root->right == NULL)
        return root->data;
        int l = solve(root->left,maxi);
        int r = solve(root->right,maxi);
        // int temp = max(l,r)+root->data;
        // int ans = max(temp,l+r+root->data); 
        // maxi = max(maxi,ans);
        // return temp;
        if(root->left && root->right){
            maxi = max(maxi,l+r+root->data);
            return max(l,r)+root->data;
        }
        // if(!root->left)
        //     return root->data + r;
        // else
        //     return root->data + l;
        return root->data+(!root->left ? r:l);
    }
    
    int maxPathSum(Node* root)
    {
        if(root==NULL)return 0;
        int maxi = INT_MIN;
        int val = solve(root,maxi);
        if(root->left && root->right)
            return maxi;
        return max(maxi, val);
}

};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}  // } Driver Code Ends