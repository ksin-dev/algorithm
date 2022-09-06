#include <iostream>
#include <vector>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
  TreeNode *pruneTree(TreeNode *root)
  {
    if (root == nullptr)
      return root;

    root->left = this->pruneTree(root->left);
    root->right = this->pruneTree(root->right);

    if (root->val == 0 && root->left == nullptr && root->right == nullptr)
      return nullptr;
    return root;
  }
};