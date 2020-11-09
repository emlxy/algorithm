#pragma once
#include "stdafx.h"

class Solution021 {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
public:
    void test()
    {
        ListNode *p1 = new ListNode(1);
        ListNode *p2 = new ListNode(2);
        ListNode *p3 = new ListNode(4);
        p1->next = p2;
        p2->next = p3;

        ListNode *pp1 = new ListNode(1);
        ListNode *pp2 = new ListNode(3);
        ListNode *pp3 = new ListNode(4);
        pp1->next = pp2;
        pp2->next = pp3;

        mergeTwoLists(p1, pp1);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *temp = nullptr;
        while (l1 || l2)  //判断条件是 l1 && l2 会更好一点
        {
            ListNode *little = nullptr;
            if (l1 && l2)
            {
                if (l1->val < l2->val)
                {
                    little = l1;
                    l1 = l1->next;
                }
                else
                {
                    little = l2;
                    l2 = l2->next;
                }
            }
            else if (l1)
            {
                little = l1;
                l1 = l1->next;
            }
            else
            {
                little = l2;
                l2 = l2->next;
            }

            if (head)
            {
                temp->next = little;
                temp = temp->next;
            }
            else
            {
                head = little;
                temp = little;
            }
        }
        return head;
    }
};