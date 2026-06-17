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
    TreeNode* insertIntoBST(TreeNode* root, int val2) {
        if(root == NULL){
            return new TreeNode(val2);
        }
        if(val2 < root->val){
            root->left = insertIntoBST(root->left, val2);
        }else{
            root->right = insertIntoBST(root->right, val2);
        }
        return root;
    }
};