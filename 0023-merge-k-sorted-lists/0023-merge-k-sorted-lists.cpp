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
 ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;

        ListNode* i = left;
        ListNode* j = right;

        while (i != NULL && j != NULL) {
            if (i->val < j->val) {
                temp->next = i;
                i = i->next;
            }
            else {
                temp->next = j;
                j = j->next;
            }
            temp = temp->next;
        }

        while (i != NULL) {
            temp->next = i;
            i = i->next;
            temp = temp->next;
        }

        while (j != NULL) {
            temp->next = j;
            j = j->next;
            temp = temp->next;
        }

        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
          if (lists.size() == 0)
            return NULL;

        ListNode* ans = lists[0];

        for (int i = 1; i < lists.size(); i++) {
            ans = merge(ans, lists[i]);
        }

        return ans;
    }
};