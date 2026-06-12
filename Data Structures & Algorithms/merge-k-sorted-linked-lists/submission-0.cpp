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
        // 1. Tạo node giả để tail luôn có điểm tựa, không bao giờ lo tail bị nullptr
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // 2. Cứ lặp cho đến khi 1 trong 2 list cạn kiệt (không quan tâm list nào dài hơn)
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;  // Nối thẳng vào tail
                l1 = l1->next;    // Tịnh tiến l1
            } else {
                tail->next = l2;  // Nối thẳng vào tail
                l2 = l2->next;    // Tịnh tiến l2
            }
            tail = tail->next;  // Kéo tail lên đứng ở node vừa nối
        }

        // 3. Nếu l1 cạn trước, nối nguyên cái đuôi của l2 vào (và ngược lại)
        if (l1 != nullptr) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }

        // 4. Trả về kết quả thực sự nằm ngay sau node giả
        return dummy.next;
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
