#include <queue>
#include "gtest/gtest.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) return nullptr;
        ListNode* p1 = head;
        ListNode* p2 = head;
        int n = 0;
        while(p1 !=nullptr) {
            p1 = p1->next;
            n++;
        }

        auto middle = n/2;
        while(--middle) p2 = p2->next;
        p2->next = p2->next->next;
        return head;
    }
};

TEST(DeleteTheMiddleNodeOfLinkedList,case1) {
    ListNode* head = new ListNode(1);
    Solution s; 
    ListNode* res = s.deleteMiddle(head);

    EXPECT_EQ(res,nullptr);
}

TEST(DeleteTheMiddleNodeOfLinkedList,case2) {
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4,node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2,node3);
    ListNode* head = new ListNode(
        1,
        node2
    );
    Solution s; 
    ListNode* res = s.deleteMiddle(head);

    EXPECT_EQ(res,head);
    EXPECT_EQ(res->next,node2);
    EXPECT_EQ(res->next->next,node4);
    EXPECT_EQ(res->next->next->next,node5);
}