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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* runner = head;
        int idx = 1;

        ListNode* new_head = head;
        ListNode* list_prev = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (runner != nullptr) {
            idx++;
            ListNode* next_runner = runner->next;
            ListNode* next_next_runner = next_runner == nullptr ? nullptr : next_runner->next;
            ListNode* temp = nullptr;

            if (idx % k == 0 && next_runner != nullptr) {
                prev = next_next_runner;
                int idx = 0;

                while (curr != next_next_runner) {
                    ListNode* next = curr->next;
                    curr->next = prev;

                    prev = curr;
                    if (idx == 0) {
                        temp = curr;
                    }
                    if (next == next_next_runner) {
                        if (list_prev != nullptr) {
                            list_prev->next = curr;
                        } else if (list_prev == nullptr) {
                            new_head = curr;
                        }
                    }
                    curr = next;
                    idx++;
                }

                list_prev = temp;

                prev = temp;
                curr = temp == nullptr ? nullptr : temp->next;
            }
            runner = idx % k == 0 && next_runner != nullptr ? prev : next_runner;
        }

        return new_head;
    }
};
