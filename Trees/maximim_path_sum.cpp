#include <iostream>
#include <algorithm>
#include <climits>
using  namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    int maxSum = INT_MIN;

    int getMaxGain(TreeNode* node) {
        if (node == nullptr) return 0;

        int leftGain = max(0, getMaxGain(node->left));
        int rightGain = max(0, getMaxGain(node->right));

        int currentPathSum = node->val + leftGain + rightGain;

        maxSum = max(maxSum, currentPathSum);

        return node->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        getMaxGain(root);
        return maxSum;
    }
};