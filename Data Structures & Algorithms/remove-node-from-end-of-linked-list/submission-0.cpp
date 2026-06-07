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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> node_map;
        ListNode* curr = head;

        while (curr != nullptr) {
            node_map.push_back(curr);
            curr = curr->next;
        }

        node_map.erase(node_map.begin() + node_map.size() - n);

        if (node_map.size() == 0) {
            ListNode* new_head = nullptr;

            return new_head;
        }

        ListNode* new_head = node_map[0];
        ListNode* tail = node_map[0];

        for (int i = 1; i < node_map.size(); i++) {
            tail->next = node_map[i];
            tail = tail->next;
        }

        tail->next = nullptr;

        return new_head;
    }
};
