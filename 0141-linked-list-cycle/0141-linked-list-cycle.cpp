/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while (head){
            if (auto it=s.find(head); it != s.end())
                return true;
            s.insert(head);
            head = head->next;
        }
        return false;
    }
};