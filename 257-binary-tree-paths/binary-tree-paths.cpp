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
    vector<string> ans;
    void dfs(TreeNode* node, vector<int>& path){
        if(!node) return;
        path.push_back(node->val);
        if(!node->left && !node->right){
            string s = "";
            for(int i=0;i<path.size();i++){
                s += to_string(path[i]);

                if(i != path.size()-1){
                    s += "->";
                }
            }
            ans.push_back(s);
        }
        dfs(node->left, path);
        dfs(node->right, path);

        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        dfs(root, path);
        return ans;
    }
};