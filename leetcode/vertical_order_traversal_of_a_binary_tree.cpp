#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>

using namespace std;

void print(vector<vector<int>> &v)
{
  for (auto &val : v)
  {
    cout << '[';
    for (auto &i : val)
    {
      cout << i << ',';
    }
    cout << ']' << '\t';
  }

  cout << endl;
}
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
  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    vector<vector<tuple<int, int>>> v;
    auto depth = get_depth(root);
    v.assign(depth + 1, vector<tuple<int, int>>());

    find_answer(v, root, 0, 0);

    vector<vector<int>> newV;

    for (auto &col : v)
    {
      if (col.size() == 0)
        continue;

      sort(col.begin(), col.end(), [](tuple<int, int> &a, tuple<int, int> &b)
           {
        if(get<0>(a) == get<0>(b))
        {
          return get<1>(a) < get<1>(b);
        }
        return get<0>(a) < get<0>(b); });

      vector<int> _v;
      for (auto &row : col)
      {
        _v.push_back(get<1>(row));
      }
      newV.push_back(_v);
    }
    return newV;
  }

  void find_answer(vector<vector<tuple<int, int>>> &v, TreeNode *root, int left, int right)
  {
    auto mid = v.size() / 2;
    if (root == nullptr)
    {
      return;
    }
    v[mid + (right - left)].push_back(make_tuple(left + right, root->val));
    find_answer(v, root->right, left, right + 1);
    find_answer(v, root->left, left + 1, right);

    return;
  }

  int get_depth(TreeNode *root, int depth = 0)
  {
    if (root == nullptr)
      return depth;
    int left = get_depth(root->left, depth + 1);
    int right = get_depth(root->right, depth + 1);

    return max(left, right);
  }
};

int main()
{
  Solution s;
  TreeNode root{
      1,
      new TreeNode{2,
                   new TreeNode{4},
                   new TreeNode{6}},
      new TreeNode{3,
                   new TreeNode{5},
                   new TreeNode{7}}};

  auto v = s.verticalTraversal(&root);
  print(v);
  return 0;
}