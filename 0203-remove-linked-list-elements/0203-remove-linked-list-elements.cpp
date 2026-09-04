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
    ListNode* removeElements(ListNode* head, int val) {
         // Dummy node to handle edge cases
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* curr = dummy;
        
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                // Skip the node
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp; // free memory
            } else {
                curr = curr->next;
            }
        }
        
        return dummy->next;
    }
};