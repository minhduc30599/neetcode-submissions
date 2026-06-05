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
    bool hasCycle(ListNode* head) {
        // unordered_set<ListNode*> address_map;
        // ListNode* curr = head;

        // while (curr != nullptr) {
        //     if (address_map.find(curr) == address_map.end()) {
        //         address_map.insert(curr);
        //     } else {
        //         return true;
        //     }

        //     curr = curr->next;
        // }

        // return false;

        if (head == nullptr || head->next == nullptr) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;   
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};
