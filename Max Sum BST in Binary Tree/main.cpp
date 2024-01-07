#include <iostream>
#include <climits>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        isValidBST(root, INT_MIN, INT_MAX, maxSum);
        return maxSum;
    }

private:
    bool isValidBST(TreeNode* node, int minValue, int maxValue, int& maxSum) {
        if (!node) {
            return true;
        }

        if (node->val <= minValue || node->val >= maxValue) {
            return false;
        }

        int leftSum = 0, rightSum = 0;
        bool isLeftBST = isValidBST(node->left, minValue, node->val, leftSum);
        bool isRightBST = isValidBST(node->right, node->val, maxValue, rightSum);

        if (isLeftBST && isRightBST) {
            int currentSum = leftSum + rightSum + node->val;
            maxSum = max(maxSum, currentSum);
            return true;
        }

        return false;
    }
};

int main() {
    
    Solution solution;

   
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->left->left->left = nullptr;
    root->left->left->right = nullptr;
    root->left->right->left = nullptr;
    root->left->right->right = nullptr;
    root->right->left->left = new TreeNode(4);
    root->right->left->right = new TreeNode(6);
    root->right->right->left = nullptr;
    root->right->right->right = nullptr;

    int result = solution.maxSumBST(root);

    cout << "Output: " << result << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left->left;
    delete root->right->left->right;
    delete root->right->right;

    return 0;
}

