//https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int d = 0;
    int m = 0;
    int maxDepth(TreeNode* root) {
        if(root==NULL) return d;
        d++;
        if(d > m) m = d;
        printf("d = %d, m= %d\n", d, m);
        maxDepth(root->left);        
        maxDepth(root->right);
        d--; //going back to root
        return m; 
    }
};
