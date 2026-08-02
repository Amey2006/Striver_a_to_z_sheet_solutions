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
    TreeNode* build(vector<int>&preorder, vector<int>& inorder,int &preidx,int left_boundry,int right_boundry,unordered_map<int,int>&mp) 
    {
        if(left_boundry>right_boundry)return nullptr;
        TreeNode* head=new TreeNode(preorder[preidx]);

        int index=mp[preorder[preidx++]];

        head->left=build(preorder,inorder,preidx,left_boundry,index-1,mp);
        head->right=build(preorder,inorder,preidx,index+1,right_boundry,mp);
        return head;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int preidx=0;
        return build( preorder, inorder,preidx,0,inorder.size()-1,mp);
    }
};