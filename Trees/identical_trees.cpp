/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    bool check_same(TreeNode* p, TreeNode* q)
    {
        if(p==nullptr && q==nullptr)return true;
        if (p == nullptr || q == nullptr) return false;
        return(p->data==q->data && check_same(p->left,q->left) && check_same(p->right,q->right));
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check_same(p,q);
    }
};