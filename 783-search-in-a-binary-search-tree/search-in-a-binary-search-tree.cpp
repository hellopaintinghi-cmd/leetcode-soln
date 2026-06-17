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
    TreeNode* searchBST(TreeNode* root, int val2) {
        if(root == NULL) return NULL;
        if(root->val == val2){
            return root;
        }
        if(val2 < root->val){
            return searchBST(root->left, val2);
        }else{
            return searchBST(root->right, val2);
        }
        return NULL;
    }
};