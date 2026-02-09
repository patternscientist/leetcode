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
    ListNode* reverseList(ListNode* head) {
        if (!head)       return nullptr;
        if (!head->next) return head;
        unordered_map<ListNode*,ListNode*> mp;
        ListNode* prev = head;
        while (head->next){
            ListNode* cur = head->next;
            mp[cur] = prev;
            prev = cur;
            head = head->next;
        }
        ListNode* dummy = new ListNode();
        dummy->next = head;
        while (mp.count(head)){
            mp[head]->next = nullptr;
            head->next = mp[head];
            head = mp[head];
        }
        return dummy->next;
    }   
};