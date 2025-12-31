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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy head simplifies edge cases; `last` always points to last node of merged list.
        ListNode dummy(0);
        ListNode* last = &dummy;

        // Invariant: dummy.next..last is the merged sorted prefix of nodes consumed from list1/list2.
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                last->next = list1;      // splice node from list1
                list1 = list1->next;     // advance list1
            } else {
                last->next = list2;      // splice node from list2
                list2 = list2->next;     // advance list2
            }
            last = last->next;           // advance tail
        }

        // Append the remaining nodes (already sorted).
        last->next = list1 ? list1 : list2;

        return dummy.next;
    }
};
