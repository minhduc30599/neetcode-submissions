class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }

        vector<int> results(nums.size(), 1);
        int multiple = 1;
        int multiple_2 = 1;

        for (int i = 0; i < nums.size(); i++) {
            results[i] = multiple;
            multiple *= nums[i]; 
        }

        for (int i = nums.size() - 1; i >=0; i--) {
            results[i] *= multiple_2;
            multiple_2 *= nums[i];
        }

        return results;
    }
};
