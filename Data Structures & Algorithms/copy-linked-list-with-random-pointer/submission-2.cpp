/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        vector<int> list_map;
        Node* curr = head;
        unordered_map<Node*, int> random_map;
        int idx = 0;

        if (curr == nullptr) {
            return nullptr;
        }

        while (curr != nullptr) {
            list_map.push_back(curr->val);
            random_map.insert({ curr, idx });
            idx++;
            curr = curr->next;
        }

        curr = head;
        unordered_map<int, int> random_map_2;
        idx = 0;

        while (curr != nullptr) {
            if (random_map.find(curr->random) != random_map.end()) {
                random_map_2.insert({ idx, random_map[curr->random] });
            }
            idx++;
            curr = curr->next;
        }

        Node* new_node = new Node(list_map[0]);
        Node* new_head = new_node;
        unordered_map<int, Node*> random_map_3;
        random_map_3.insert({ 0, new_node });
        for (int i = 1; i < list_map.size(); i++) {
            Node* new_node = new Node(list_map[i]);
            random_map_3.insert({ i, new_node });
            new_head->next = new_node;
            new_head = new_node;
        }
        new_head->next = nullptr;

        new_head = new_node;
        idx = 0;
        while (new_head != nullptr) {
            if (random_map_2.find(idx) != random_map_2.end()) {
                if (random_map_3.find(random_map_2[idx]) != random_map_3.end()) {
                    new_head->random = random_map_3[random_map_2[idx]];
                } else {
                    new_head->random = nullptr;
                }
            } else {
                new_head->random = nullptr;
            }
            idx++;
            new_head = new_head->next;
        }

        return new_node;
    }
};
