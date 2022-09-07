#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root == nullptr) return "";
        string s = std::to_string(root->val);

        if(root->left !=nullptr) s += "(" + tree2str(root->left) +")";
        else if(root->right !=nullptr) s += "()";
        if(root->right !=nullptr) s += "(" + tree2str(root->right) + ")";
        
        return s;
    }

};

int main() {
    Solution solution;
    auto root = TreeNode {
        1,
        new TreeNode {
            2,
            nullptr,
            new TreeNode(4)
        },
        new TreeNode(3)
    };

    // auto root = TreeNode {
    //     1,
    //     new TreeNode {
    //         2,
    //         new TreeNode(4),
    //         nullptr
    //     },
    //     new TreeNode(3)
    // };
    auto s = solution.tree2str(&root);

    cout << s << endl;

    return 0;
}