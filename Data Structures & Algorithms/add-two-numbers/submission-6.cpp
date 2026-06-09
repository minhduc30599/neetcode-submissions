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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_cp = l1;
        ListNode* l2_cp = l2;
        int idx_1 = 0;
        int idx_2 = 0;

        while (l1_cp != nullptr) {
            idx_1++;
            l1_cp = l1_cp->next;
        }

        while (l2_cp != nullptr) {
            idx_2++;
            l2_cp = l2_cp->next;
        }

        ListNode* l_cp = idx_1 > idx_2 ? l1 : l2;
        l1_cp = l1;
        l2_cp = l2;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int idx = 0;
        int temp = 0;

        while (l_cp != nullptr) {
            int total = 0;

            if (l1_cp != nullptr && l2_cp != nullptr) {
                total = l1_cp->val + l2_cp->val + temp;
            } else if (l1_cp != nullptr && l2_cp == nullptr) {
                total = l1_cp->val + 0 + temp;
            } else if (l1_cp == nullptr && l2_cp != nullptr) {
                total = l2_cp->val + 0 + temp;
            }

            string temp_str = to_string(total);

            if (temp_str.length() > 1) {
                temp = temp_str[0] - '0';

                if (idx > 0) {
                    tail->next = new ListNode(temp_str[1] - '0');
                    tail = tail->next;
                } else {
                    head = new ListNode(temp_str[1] - '0');
                    tail = head;
                }
            } else if (temp_str.length() == 1) {
                temp = 0;
                if (idx > 0) {
                    tail->next = new ListNode(stoi(temp_str));
                    tail = tail->next;
                } else {
                    head = new ListNode(stoi(temp_str));
                    tail = head;
                }
            }

            idx++;
            l_cp = l_cp->next;
            l1_cp = (l1_cp != nullptr) ? l1_cp->next : nullptr;
            l2_cp = (l2_cp != nullptr) ? l2_cp->next : nullptr;
        }

        if (temp > 0) {
            tail->next = new ListNode(temp);
            tail = tail->next;
        }

        tail->next = nullptr;

        return head;
    }
};
