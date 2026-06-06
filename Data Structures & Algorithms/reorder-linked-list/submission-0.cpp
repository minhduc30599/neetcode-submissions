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
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        vector<ListNode*> address_vector;

        while (curr->next != nullptr) {
            if (curr != head) {
                address_vector.push_back(curr);
            }
            curr = curr->next;
        }

        head->next = curr;

        int left = 0;
        int right = address_vector.size() - 1;
        bool left_flag = true;
        while (left <= right) {
            if (left_flag) {
                curr->next = address_vector[left];
                left++;
            } else {
                curr->next = address_vector[right];
                right--;
            }

            left_flag = !left_flag;
            curr = curr->next;
        }

        curr->next = nullptr;
    }
};
