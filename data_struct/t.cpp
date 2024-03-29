#include <iostream>
#include <queue>
#include <string>

struct node
{
  /* data */
  std::string position;
  node *first;
  node *second;
};

struct org_tree
{
  /* data */
  node *root;
  static org_tree create_org_structure(const std::string &pos)
  {
    org_tree tree;
    tree.root = new node{pos, nullptr, nullptr};
    return tree;
  }

  static node *find(node *root, const std::string &value)
  {
    if (root == nullptr)
      return nullptr;
    if (root->position == value)
      return root;

    auto firstFound = org_tree::find(root->first, value);

    if (firstFound != nullptr)
      return firstFound;

    return org_tree::find(root->second, value);
  }

  bool addSubordinate(const std::string &manager, const std::string &subordinate)
  {
    auto managerNode = org_tree::find(root, manager);

    if (!managerNode)
    {
      std::cout << manager << "을 찾을 수 없습니다." << std::endl;
      return false;
    }

    if (managerNode->first && managerNode->second)
    {
      std::cout << manager << "아래에" << subordinate << "을 추가 할 수 없습니다." << std::endl;
      return false;
    }

    if (!managerNode->first)
      managerNode->first = new node{subordinate, nullptr, nullptr};
    else
      managerNode->second = new node{subordinate, nullptr, nullptr};

    std::cout << manager << "아래에" << subordinate << "을 추가했습니다." << std::endl;

    return true;
  }
  static void preOrder(node *start)
  {
    if (!start)
      return;

    std::cout << start->position << ",";

    preOrder(start->first);
    preOrder(start->second);
  }

  static void inOrder(node *start)
  {
    if (!start)
      return;

    inOrder(start->first);
    std::cout << start->position << ",";
    inOrder(start->second);
  }

  static void postOrder(node *start)
  {
    if (!start)
      return;

    postOrder(start->first);
    postOrder(start->second);
    std::cout << start->position << ",";
  }

  static void levelOrder(node *start)
  {
    if (!start)
      return;

    std::queue<node *> q;
    q.push(start);

    while (!q.empty())
    {
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
        auto current = q.front();

        q.pop();

        std::cout << current->position << ",";
        if (current->first)
          q.push(current->first);
        if (current->second)
          q.push(current->second);
      }

      std::cout << std::endl;
    }
  }
};

int main()
{
  auto tree = org_tree::create_org_structure("CEO");

  tree.addSubordinate("CEO", "부사장");
  tree.addSubordinate("부사장", "IT부장");
  tree.addSubordinate("부사장", "마케팅부장");
  tree.addSubordinate("IT부장", "보안 팁장");
  tree.addSubordinate("IT부장", "앱 개발 팀장");
  tree.addSubordinate("마케팅부장", "물류팀장");
  tree.addSubordinate("마케팅부장", "홍보팀장");
  tree.addSubordinate("부사장", "재무부장");

  org_tree::preOrder(tree.root);
  std::cout << std::endl;
  org_tree::inOrder(tree.root);
  std::cout << std::endl;
  org_tree::postOrder(tree.root);
  std::cout << std::endl;

  org_tree::levelOrder(tree.root);

  return 0;
}