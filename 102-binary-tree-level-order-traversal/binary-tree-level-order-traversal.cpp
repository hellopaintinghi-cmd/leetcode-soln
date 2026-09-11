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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        vector<vector<int>> ans;

        while(!q.empty()){
            auto it = q.front();
            TreeNode* node = it.first;
            int level = it.second;
            q.pop();

            if(level == ans.size()){
                ans.push_back({});
            }

            ans[level].push_back(node->val);
            
            if(node->left){
                q.push({node->left, level + 1});
            }

            if(node->right){
                q.push({node->right, level + 1});
            }
        }

        return ans;
    }
};