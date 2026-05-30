class Solution {
   public:
    int findMin(vector<int>& nums) {
        int result = nums[0];

        for (int num : nums) {
            if (num < result) {
                result = num;
            }
        }

        return result;
    }
};
