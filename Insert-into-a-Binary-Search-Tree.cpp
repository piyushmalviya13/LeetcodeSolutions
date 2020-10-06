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
    void insert(TreeNode* root, int val) {
        if(root->val > val) {
            if(root->left == NULL) {
                TreeNode *naya = new TreeNode(val);
                root->left = naya;
                return;
            }
            else {
                insert(root->left, val);
            }
        }
        else {
            if(root->right == NULL) {
                TreeNode *naya = new TreeNode(val);
                root->right = naya;
                return;
            }
            else {
                insert(root->right, val);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            TreeNode *naya = new TreeNode(val);
            root = naya;
        }
        else insert(root, val);
        return root;
    }
};
