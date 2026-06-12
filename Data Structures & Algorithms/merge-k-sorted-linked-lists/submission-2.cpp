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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        int idx1 = 0;
        int idx2 = 0;

        while (ptr1 != nullptr) {
            idx1++;
            ptr1 = ptr1->next;
        }

        while (ptr2 != nullptr) {
            idx2++;
            ptr2 = ptr2->next;
        }

        ptr1 = l1;
        ptr2 = l2;
        ListNode* new_head = nullptr;
        ListNode* tail = new_head;
        int idx3 = 0;

        do {
            if (ptr1 != nullptr && ptr2 != nullptr && ptr1->val > ptr2->val) {
                if (idx3 == 0) {
                    new_head = ptr2;
                    tail = new_head;
                } else {
                    tail->next = ptr2;
                }
                ptr2 = ptr2->next;
            } else if (ptr1 != nullptr && ptr2 != nullptr && ptr1->val <= ptr2->val) {
                if (idx3 == 0) {
                    new_head = ptr1;
                    tail = new_head;
                } else {
                    tail->next = ptr1;
                }
                ptr1 = ptr1->next;
            } else if (ptr1 == nullptr && ptr2 != nullptr) {
                if (idx3 == 0) {
                    new_head = ptr2;
                    tail = new_head;
                } else {
                    tail->next = ptr2;
                }
                ptr2 = ptr2->next;
            } else if (ptr1 != nullptr && ptr2 == nullptr) {
                if (idx3 == 0) {
                    new_head = ptr1;
                    tail = new_head;
                } else {
                    tail->next = ptr1;
                }
                ptr1 = ptr1->next;
            } else if (ptr1 == nullptr && ptr2 == nullptr) {
                break;
            }

            if (idx3 > 0) {
                tail = tail->next;
            }
            idx3++;
        } while (tail != nullptr);

        if (tail != nullptr) tail->next = nullptr;

        return new_head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        int n = lists.size();

        for (int step = 1; step < n; step *= 2) {
            for (int i = 0; i + step < n; i += step * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + step]);
            }
        }

        return lists[0];
    }
};