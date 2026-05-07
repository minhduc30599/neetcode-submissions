class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // time: O(n)
        // space: O(n)
        unordered_map<int, int> nums_map;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int, int>::iterator item = nums_map.find(nums[i]);
            if (item == nums_map.end()) {
                nums_map.insert({ nums[i], i });
            } else {
                return true;
            }
        }

        return false;

        // time: O(nlogn)
        // space: O(1)
        // sort(nums.begin(), nums.end());

        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] == nums[i + 1]) {
        //         return true;
        //     }
        // }

        // return false;
    }
};