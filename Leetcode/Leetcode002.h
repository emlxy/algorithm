#include "stdafx.h"

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/

class Solution002 {

public:
    void test()
    {
        ListNode *l1 = new ListNode(3);
        ListNode *l2 = new ListNode(9);
        addTwoNumbers(l1, l2);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *temp = nullptr;
        int bFlag = 0;
        while (l1 || l2)
        {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;   //注意l1.l2 next处理
            ListNode *p = new ListNode((num1 + num2 + bFlag) % 10);
            bFlag = (num1 + num2 + bFlag) / 10;
            if (head)
            {
                temp->next = p;
                temp = p;
            }
            else
                head = temp = p;
        }
        if (bFlag > 0)  //这一步也需要注意
        {
            ListNode *p = new ListNode(bFlag);
            temp->next = p;
        }

        return head;
    }
};
