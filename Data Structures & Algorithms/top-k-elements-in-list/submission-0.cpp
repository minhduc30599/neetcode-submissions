class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int>::iterator item = map.find(nums[i]);

            if (item == map.end()) {
                map.insert({nums[i], 1});
            } else {
                map[nums[i]]++;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<std::pair<int, int>>>
            min_heap;
        vector<int> results;
        for (const auto& [key, value] : map) {
            min_heap.push({value, key});

            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        while (!min_heap.empty()) {
            results.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return results;
    }
};
