class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int result = 0;

        for (int num : num_set) {
            if (num_set.find(num - 1) == num_set.end()) {
                int length = 1;
                int curr_num = num;

                while (num_set.find(curr_num + 1) != num_set.end()) {
                    length += 1;
                    curr_num += 1;
                } 

                if (length > result) {
                    result = length;
                }
            }
        }

        return result;
    }
};
