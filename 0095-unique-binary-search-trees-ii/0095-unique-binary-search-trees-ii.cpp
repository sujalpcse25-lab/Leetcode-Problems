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
    vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generateTreesHelper(1, n);
}

vector<TreeNode*> generateTreesHelper(int start, int end) {
    vector<TreeNode*> allTrees;

    if (start > end) {
        allTrees.push_back(nullptr); // Base case: empty tree
        return allTrees;
    }

    for (int i = start; i <= end; i++) {
        // Generate all left and right subtrees
        vector<TreeNode*> leftTrees = generateTreesHelper(start, i - 1);
        vector<TreeNode*> rightTrees = generateTreesHelper(i + 1, end);

        // Combine left and right trees with the current root
        for (TreeNode* left : leftTrees) {
            for (TreeNode* right : rightTrees) {
                TreeNode* currentNode = new TreeNode(i);
                currentNode->left = left;
                currentNode->right = right;
                allTrees.push_back(currentNode);
            }
        }
    }
    return allTrees;
}

};