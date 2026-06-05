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
        ListNode* first_ptr = list1;
        ListNode* second_ptr = list2;
        ListNode* result = nullptr;
        ListNode* tail = nullptr;

        while (first_ptr != nullptr || second_ptr != nullptr) {
            if (first_ptr != nullptr && second_ptr != nullptr && first_ptr->val < second_ptr->val) {
                if (result == nullptr) {
                    result = first_ptr;
                    tail = first_ptr;
                } else {
                    tail->next = first_ptr;
                    tail = tail->next;
                }
                first_ptr = first_ptr->next;
            } else if (first_ptr != nullptr && second_ptr != nullptr && first_ptr->val >= second_ptr->val) {
                if (result == nullptr) {
                    result = second_ptr;
                    tail = second_ptr;
                } else {
                    tail->next = second_ptr;
                    tail = tail->next;
                }
                second_ptr = second_ptr->next;
            } else if (first_ptr == nullptr && second_ptr != nullptr) {
                if (result == nullptr) {
                    result = second_ptr;
                    tail = second_ptr;
                } else {
                    tail->next = second_ptr;
                    tail = tail->next;
                }
                second_ptr = second_ptr->next;
            } else if (first_ptr != nullptr && second_ptr == nullptr) {
                if (result == nullptr) {
                    result = first_ptr;
                    tail = first_ptr;
                } else {
                    tail->next = first_ptr;
                    tail = tail->next;
                }
                first_ptr = first_ptr->next;
            }
        }

        return result;
    }
};
