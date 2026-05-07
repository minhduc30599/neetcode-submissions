class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Time: if array is already sorted: O(n), if not: O(nLogn)
        // Space: O(1)
        // if (nums.size() == 0) {
        //     return {};
        // }

        // sort(nums.begin(), nums.end());
        // int ptr1 = 0;
        // int ptr2 = nums.size() - 1;

        // while (ptr1 < ptr2) {
        //     if (nums[ptr1] + nums[ptr2] > target) {
        //         ptr2--;
        //     } else if (nums[ptr1] + nums[ptr2] < target) {
        //         ptr1++;
        //     } else {
        //         return { ptr1, ptr2 };
        //     }
        // }

        // return {};

        // Time: O(n)
        // Space: O(n)
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int other = target - nums[i];
            unordered_map<int, int>::iterator item = map.find(other);

            if (item == map.end()) {
                map.insert({ nums[i], i });
            } else {
                return map[other] > i ? vector<int>{i, map[other]} : vector<int>{map[other], i};
            }
        }

        return {};
    }
};
