class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            while (!dq.empty() && nums[right] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(right);

            if (dq.front() < right - k + 1) {
                dq.pop_front();
            }

            if (right + 1 >= k) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
