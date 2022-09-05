#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &v)
{
  for (auto &row : v)
  {
    cout << '[';
    for (auto &val : row)
    {
      cout << val << ',';
    }
    cout << "] ";
  }
  cout << endl;
}

class Node
{
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val)
  {
    val = _val;
  }

  Node(int _val, vector<Node *> _children)
  {
    val = _val;
    children = _children;
  }
};

class Solution
{
public:
  vector<vector<int>> levelOrder(Node *root)
  {
    vector<Node *> v;
    if (root != nullptr)
      v.push_back(root);

    return BFS(v);
  }

  vector<vector<int>> BFS(vector<Node *> &parent)
  {
    vector<int> v;
    vector<Node *> children;
    vector<vector<int>> result;

    for (auto child : parent)
    {
      v.push_back(child->val);
      if (child->children.size() == 0)
        continue;
      children.insert(children.end(), child->children.begin(), child->children.end());
    }

    if (children.size() != 0)
      result = BFS(children);

    if (v.size() != 0)
      result.insert(result.begin(), v);

    return result;
  }
};

int main()
{
  Solution solution;

  // Node root(1, vector<Node *>{
  //                  new Node(2),
  //                  new Node(3, vector<Node *>{
  //                                  new Node(6),
  //                                  new Node(7,
  //                                           vector<Node *>{
  //                                               new Node(11,
  //                                                        vector<Node *>{
  //                                                            new Node(14)})})}),
  //                  new Node(4, vector<Node *>{new Node(8, vector<Node *>{new Node(12)})}),
  //                  new Node(5, vector<Node *>{new Node(9, vector<Node *>{new Node(13)}), new Node(10)}),
  //              });

  auto result = solution.levelOrder(nullptr);

  print(result);
  return 0;
}