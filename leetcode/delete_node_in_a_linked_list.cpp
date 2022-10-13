#include <iostream>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = nullptr;
        while(node->next != nullptr) {
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        prev->next = nullptr;
        
    }
};

TEST(DeleteText,test) {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    Solution s;

    s.deleteNode(node2);

    EXPECT_EQ(node1->val, 1);
    EXPECT_EQ(node2->val, 3);
    EXPECT_EQ(node2->next, nullptr);
}