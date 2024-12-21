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
private:
    void pairDFS(int level,TreeNode* lN , TreeNode* rN)
    {
        if(level%2) swap(lN->val,rN->val);
        if(lN->left!=NULL)
        {
            pairDFS(level+1,lN->left,rN->right);
            pairDFS(level+1,lN->right,rN->left);
        }
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root || root->left==NULL) return root;
        pairDFS(1,root->left,root->right);
        return root;
    }
};