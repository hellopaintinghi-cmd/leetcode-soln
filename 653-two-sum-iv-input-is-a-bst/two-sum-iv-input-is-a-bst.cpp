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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator {
    stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        pushLeft(node->right);

        return node->val;
    }
};

class BSTReverseIterator {
    stack<TreeNode*> st;

public:
    BSTReverseIterator(TreeNode* root) {
        pushRight(root);
    }

    void pushRight(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->right;
        }
    }

    int before() {
        TreeNode* node = st.top();
        st.pop();

        pushRight(node->left);

        return node->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        if (!root) return false;

        BSTIterator left(root);
        BSTReverseIterator right(root);

        int i = left.next();      // smallest value
        int j = right.before();   // largest value

        while (i < j) {

            int sum = i + j;

            if (sum == k)
                return true;

            else if (sum < k)
                i = left.next();

            else
                j = right.before();
        }

        return false;
    }
};