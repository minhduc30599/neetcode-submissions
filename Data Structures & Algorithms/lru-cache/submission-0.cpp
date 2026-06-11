class LRUCache {
   private:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            prev = nullptr;
            next = nullptr;
        }
    };

    int cap;
    unordered_map<int, Node*> cache_map;
    Node* head;
    Node* tail;

    void remove_from_back() {
        Node* temp_0 = tail->prev;
        Node* temp_1 = temp_0->prev;

        tail->prev = temp_1;
        temp_1->next = tail;
        temp_0->next = nullptr;
        temp_0->prev = nullptr;
        cache_map.erase(temp_0->key);
        delete temp_0;
    }

    void add_to_head(Node* item) {
        Node* temp = head->next;
        head->next = item;
        item->next = temp;
        item->prev = head;
        temp->prev = item;
    }

    void move_to_head(Node* item) {
        Node* item_prev = item->prev;
        Node* item_next = item->next;

        if (item_prev != head) {
            item_prev->next = item_next;
            item_next->prev = item_prev;
            add_to_head(item);
        }
    }

   public:
    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        auto item = cache_map.find(key);

        if (item == cache_map.end()) {
            return -1;
        }

        move_to_head(cache_map[key]);

        return cache_map[key]->value;
    }

    void put(int key, int value) {
        if (cap == 0) {
            return;
        }
        
        auto item = cache_map.find(key);

        if (item != cache_map.end()) {
            cache_map[key]->value = value;
            move_to_head(cache_map[key]);
        } else {
            if (cache_map.size() >= cap) {
                remove_from_back();
            }

            Node* new_node = new Node(key, value);
            cache_map.insert({key, new_node});
            add_to_head(new_node);
        }

    }
};
